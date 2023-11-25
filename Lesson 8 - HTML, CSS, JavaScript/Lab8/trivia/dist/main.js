"use strict";
class TriviaApi {
    triviaUrl;
    amount;
    /* Question category */
    category;
    /* Easy medium or hard */
    difficulty;
    /* boolean or multiple - types of answers */
    type;
    encode;
    /*  If one of these options is empty, it should not be sent as a param */
    constructor() {
        this.triviaUrl = "https://opentdb.com/api.php";
        this.amount = 10;
    }
    async getQuestions(amountOfQuestions) {
        if (amountOfQuestions) {
            this.amount = amountOfQuestions;
        }
        const params = new URLSearchParams({
            amount: this.amount.toString(),
        });
        if (this.category)
            params.append("category", this.category.toString());
        if (this.difficulty)
            params.append("difficulty", this.difficulty);
        if (this.type)
            params.append("type", this.type);
        if (this.encode)
            params.append("encode", this.encode);
        const urlWithParams = `${this.triviaUrl}?${params.toString()}`;
        try {
            const response = await fetch(urlWithParams);
            const result = await response.json();
            return result.results[0];
        }
        catch (error) {
            console.log(error);
            return error;
        }
    }
}
class ElementGetter {
    static getElementById(id) {
        const element = document.getElementById(id);
        if (!element)
            throw new Error(`Element with id '${id}' not found`);
        return element;
    }
}
class QuestionEngine {
    api;
    targetDiv;
    constructor() {
        this.api = new TriviaApi();
    }
    async renderQuestion(divId, number) {
        this.targetDiv = ElementGetter.getElementById(divId);
        if (!this.targetDiv)
            return;
        const question = await this.api.getQuestions(number ? number : 10);
        console.log(question);
        this.targetDiv.innerHTML += `<p>${question.question}</p><p>${question.correct_answer}</p>`;
        question.incorrect_answers.forEach((answer) => {
            this.targetDiv.innerHTML += `<p>${answer}</p>`;
        });
    }
}
const renderer = new QuestionEngine();
renderer.renderQuestion("multipleChoice", 1);
//# sourceMappingURL=main.js.map