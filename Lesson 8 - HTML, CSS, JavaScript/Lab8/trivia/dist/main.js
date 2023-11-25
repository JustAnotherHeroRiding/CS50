"use strict";
var ElementType;
(function (ElementType) {
    ElementType["DIV"] = "div";
    ElementType["IMG"] = "img";
})(ElementType || (ElementType = {}));
class ImprovedElementCreator {
    static createElement(elementType, classes, size, textContent) {
        const element = document.createElement(elementType);
        if (!classes) {
            return element;
        }
        if (typeof classes === "string") {
            element.classList.add(classes);
        }
        else {
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
        const childRowDiv = ImprovedElementCreator.createElement(ElementType.DIV, [
            "flex",
            "flex-row",
            "border",
            "rounded-md",
            "px-4",
            "py-2",
            "justify-between",
        ]);
        const question = await this.api.getQuestions(number ? number : 10);
        console.log(question);
        this.targetDiv.innerHTML += `<p>${question.question}</p>`;
        childRowDiv.innerHTML += `<button class="px-4 py-2 mx-4">${question.correct_answer}</button>`;
        question.incorrect_answers.forEach((answer) => {
            childRowDiv.innerHTML += `<button class="px-4 py-2 mx-4">${answer}</button>`;
        });
        this.targetDiv.appendChild(childRowDiv);
    }
    start(page) {
        if (page === "home") {
            this.renderQuestion("multipleChoice", 1);
        }
    }
}
const renderer = new QuestionEngine();
//renderer.start("home");
//# sourceMappingURL=main.js.map