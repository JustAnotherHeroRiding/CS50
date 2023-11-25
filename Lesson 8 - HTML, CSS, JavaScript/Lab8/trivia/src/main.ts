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

  async getQuestions(amountOfQuestions?: number) {
    if (amountOfQuestions) {
      this.amount = amountOfQuestions;
    }

    const params = new URLSearchParams({
      amount: this.amount.toString(),
    });

    if (this.category) params.append("category", this.category.toString());
    if (this.difficulty) params.append("difficulty", this.difficulty);
    if (this.type) params.append("type", this.type);
    if (this.encode) params.append("encode", this.encode);

    const urlWithParams = `${this.triviaUrl}?${params.toString()}`;

    try {
      const response = await fetch(urlWithParams);
      const result = await response.json();
      return result.results[0];
    } catch (error) {
      console.log(error);
      return error;
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
    this.targetDiv = ElementGetter.getElementById<HTMLDivElement>(divId);
    if (!this.targetDiv) return;
    const question = await this.api.getQuestions(number ? number : 10);
    console.log(question);
    this.targetDiv!.innerHTML += `<p>${question.question}</p><p>${question.correct_answer}</p>`;
    question.incorrect_answers.forEach((answer: string) => {
      this.targetDiv!.innerHTML += `<p>${answer}</p>`;
    });
  }
}

const renderer = new QuestionEngine();
renderer.renderQuestion("multipleChoice", 1);
