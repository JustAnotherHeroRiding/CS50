enum ElementType {
  DIV = "div",
  IMG = "img",
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
          return result.results[0];
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

  async renderQuestion(divId: string, number?: number) {
    const targetDiv = ElementGetter.getElementById<HTMLDivElement>(divId);
    if (!targetDiv) return;
    const childRowDiv = ImprovedElementCreator.createElement(ElementType.DIV, [
      "flex",
      "flex-row",
      "border",
      "border-indigo-600",
      "rounded-md",
      "px-4",
      "py-2",
      "gap-8",
    ]);
    const question = await this.api.getQuestions(number ? number : 10);
    console.log(question);
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
    targetDiv.innerHTML += `<p>${question.question}</p>`;
    childRowDiv!.innerHTML += `<button class="px-4 py-2 border border-black bg-trivia-100 text-trivia-400 rounded-md">${question.correct_answer}</button>`;
    question.incorrect_answers.forEach((answer: string) => {
      childRowDiv!.innerHTML += `<button class="px-4 py-2 border border-black bg-trivia-100 text-trivia-400 rounded-md">${answer}</button>`;
    });
    targetDiv.appendChild(childRowDiv);
  }

  renderFreeText(
    question: Question,
    childRowDiv: HTMLDivElement,
    targetDiv: HTMLDivElement
  ) {
    targetDiv.innerHTML += `<p>${question.question}</p>`;
    childRowDiv!.innerHTML += `<input type="text" class="border border-black rounded-md px-4 py-2" placeholder="Enter your answer here">`;
    targetDiv.appendChild(childRowDiv);
  }

  start(page: string) {
    if (page === "home") {
      //this.renderQuestion("multipleChoice", 1);
      this.renderQuestion("freeText", 1);
    }
  }
}

const renderer = new QuestionEngine();
renderer.start("home");
