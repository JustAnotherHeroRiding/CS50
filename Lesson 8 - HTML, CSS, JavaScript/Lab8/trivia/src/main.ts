enum ElementType {
  DIV = "div",
  IMG = "img",
  P = "p",
  H3 = "h3",
  BUTTON = "button",
  INPUT = "input",
}

interface Question {
  type: string;
  difficulty: string;
  category: string;
  question: string;
  correct_answer: string;
  incorrect_answers: string[];
}

class ImprovedElementCreator {
  static createElement(
    elementType: ElementType,
    classes?: string | string[],
    size?: [number, number],
    textContent?: string
  ) {
    const element = document.createElement(elementType);
    if (!classes) {
      return element;
    }
    if (typeof classes === "string") {
      element.classList.add(classes);
    } else {
      element.classList.add(...classes);
    }

    if (size) {
      const [width, height] = size;
      element.style.width = `${width}px`;
      element.style.height = `${height}px`;
    }

    if (textContent) {
      element.textContent = textContent;
    }
    return element;
  }
}

class TriviaApi {
  private readonly triviaUrl: string;
  private amount: number;
  /* Question category */
  private category?: number;
  /* Easy medium or hard */
  private difficulty?: string;
  /* boolean or multiple - types of answers */
  private type?: string;
  private encode?: string;
  /*  If one of these options is empty, it should not be sent as a param */

  constructor() {
    this.triviaUrl = "https://opentdb.com/api.php";
    this.amount = 10;
  }

  async tryFetchQuestions(retryCount: number = 3): Promise<any> {
    if (retryCount === 0) {
      throw new Error("Failed to fetch questions after multiple attempts");
    }

    const params = new URLSearchParams({
      amount: this.amount.toString(),
    });
    if (this.category) params.append("category", this.category.toString());
    if (this.difficulty) params.append("difficulty", this.difficulty);
    if (this.type) params.append("type", this.type);
    if (this.encode) params.append("encode", this.encode);

    const urlWithParams = `${this.triviaUrl}?${params.toString()}`;

    return fetch(urlWithParams)
      .then((response) => response.json())
      .then((result) => {
        if (result.results && result.results.length > 0) {
          return result.results;
        } else {
          return this.tryFetchQuestions(retryCount - 1);
        }
      })
      .catch((error) => {
        console.error(error);
        return this.tryFetchQuestions(retryCount - 1);
      });
  }

  async getQuestions(amountOfQuestions?: number) {
    if (amountOfQuestions) {
      this.amount = amountOfQuestions;
    }

    try {
      return await this.tryFetchQuestions();
    } catch (error) {
      console.log(error);
      return null;
    }
  }
}

class ElementGetter {
  static getElementById<T extends HTMLElement>(id: string): T {
    const element = document.getElementById(id);
    if (!element) throw new Error(`Element with id '${id}' not found`);
    return element as T;
  }
}

class QuestionEngine {
  api: TriviaApi;
  targetDiv?: HTMLDivElement;

  constructor() {
    this.api = new TriviaApi();
  }

  renderQuestion(divId: string, question: Question) {
    const targetDiv = ElementGetter.getElementById<HTMLDivElement>(divId);
    if (!targetDiv) return;
    const childRowDiv = ImprovedElementCreator.createElement(ElementType.DIV, [
      "flex",
      "flex-row",
      "px-4",
      "py-2",
      "gap-4",
    ]) as HTMLDivElement;

    if (divId === "multipleChoice") {
      this.renderMultipleChoice(question, childRowDiv, targetDiv);
    } else if (divId === "freeText") {
      this.renderFreeText(question, childRowDiv, targetDiv);
    }
  }

  renderMultipleChoice(
    question: Question,
    childRowDiv: HTMLDivElement,
    targetDiv: HTMLDivElement
  ) {
    targetDiv.innerHTML = ""; // Clear previous content
    const questionTitle = ImprovedElementCreator.createElement(
      ElementType.H3,
      ["text-3xl", "w-1/3", "text-center"],
      undefined,
      question.question
    );
    targetDiv.appendChild(questionTitle);

    const answers = [question.correct_answer, ...question.incorrect_answers];
    answers.forEach((answer) => {
      const answerButton = ImprovedElementCreator.createElement(
        ElementType.BUTTON,
        [
          "px-4",
          "py-2",
          "border",
          "border-black",
          "text-trivia-400",
          "rounded-md",
        ],
        undefined,
        answer
      ) as HTMLButtonElement;
      answerButton.addEventListener("click", () =>
        this.checkAnswer(question, answer, answerButton, "multipleChoice")
      );
      childRowDiv.appendChild(answerButton);
    });

    targetDiv.appendChild(childRowDiv);
  }

  renderFreeText(
    question: Question,
    childRowDiv: HTMLDivElement,
    targetDiv: HTMLDivElement
  ) {
    const questionTitle = ImprovedElementCreator.createElement(
      ElementType.H3,
      ["text-3xl", "w-1/3", "text-center"],
      undefined,
      question.question
    );
    const input = ImprovedElementCreator.createElement(ElementType.INPUT, [
      "border",
      "border-black",
      "rounded-md",
      "px-4",
      "py-2",
    ]) as HTMLInputElement;
    input.placeholder = "Enter your answer here";
    childRowDiv.appendChild(input);
    targetDiv.appendChild(questionTitle);
    targetDiv.appendChild(childRowDiv);
  }

  checkAnswer(
    question: Question,
    answer: string,
    source: HTMLButtonElement,
    type: string
  ) {
    if (type === "multipleChoice") {
      if (question.correct_answer === answer) {
        source.classList.toggle("bg-green-600");
        const correct = ImprovedElementCreator.createElement(
          ElementType.P,
          ["text-green-600", "text-2xl"],
          undefined,
          "correct"
        );
        source.parentElement!.parentElement!.appendChild(correct);
        setTimeout(() => {
          source.classList.toggle("bg-green-600");
          correct.remove();
        }, 2000);
      } else {
        source.classList.toggle("bg-red-600");
        const incorrect = ImprovedElementCreator.createElement(
          ElementType.P,
          ["text-red-600", "text-2xl"],
          undefined,
          "incorrect"
        );
        source.parentElement!.parentElement!.appendChild(incorrect);
        source.disabled = true;
        setTimeout(() => {
          source.disabled = false;
          incorrect.remove();
          source.classList.toggle("bg-red-600");
        }, 1000);
      }
    } else if (type == "freeText") {
      if (question.correct_answer === answer) {

      }
    }
  }

  async start(page: string, number?: number) {
    if (page === "home") {
      const questions = (await this.api.getQuestions(
        number ? number + 1 : 10
      )) as Question[];

      if (questions.length > 1) {
        // Render all but the last question as multiple choice
        questions.slice(0, -1).forEach((question) => {
          this.renderQuestion("multipleChoice", question);
        });
        // Render the last question as free text
        this.renderQuestion("freeText", questions[questions.length - 1]);
      } else if (questions.length === 1) {
        // If only one question is fetched, render it as needed
        this.renderQuestion("multipleChoice", questions[0]); // or "freeText"
      } else {
        console.error("No questions fetched");
      }
    }
  }
}

const renderer = new QuestionEngine();
renderer.start("home", 1);
