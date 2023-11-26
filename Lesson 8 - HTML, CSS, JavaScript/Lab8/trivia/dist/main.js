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
    async tryFetchQuestions(retryCount = 3) {
        if (retryCount === 0) {
            throw new Error("Failed to fetch questions after multiple attempts");
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
        return fetch(urlWithParams)
            .then((response) => response.json())
            .then((result) => {
            if (result.results && result.results.length > 0) {
                return result.results;
            }
            else {
                return this.tryFetchQuestions(retryCount - 1);
            }
        })
            .catch((error) => {
            console.error(error);
            return this.tryFetchQuestions(retryCount - 1);
        });
    }
    async getQuestions(amountOfQuestions) {
        if (amountOfQuestions) {
            this.amount = amountOfQuestions;
        }
        try {
            return await this.tryFetchQuestions();
        }
        catch (error) {
            console.log(error);
            return null;
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
    renderQuestion(divId, question) {
        const targetDiv = ElementGetter.getElementById(divId);
        if (!targetDiv)
            return;
        const childRowDiv = ImprovedElementCreator.createElement(ElementType.DIV, [
            "flex",
            "flex-row",
            "px-4",
            "py-2",
            "gap-4",
        ]);
        if (divId === "multipleChoice") {
            this.renderMultipleChoice(question, childRowDiv, targetDiv);
        }
        else if (divId === "freeText") {
            this.renderFreeText(question, childRowDiv, targetDiv);
        }
    }
    renderMultipleChoice(question, childRowDiv, targetDiv) {
        targetDiv.innerHTML += `<h3 class="text-3xl w-1/3 text-center">${question.question}</h3>`;
        childRowDiv.innerHTML += `<button class="px-4  py-2 border border-black bg-trivia-200 text-trivia-400 rounded-md">${question.correct_answer}</button>`;
        question.incorrect_answers.forEach((answer) => {
            childRowDiv.innerHTML += `<button class="px-4 py-2 border border-black bg-trivia-200 text-trivia-400 rounded-md">${answer}</button>`;
        });
        targetDiv.appendChild(childRowDiv);
    }
    renderFreeText(question, childRowDiv, targetDiv) {
        targetDiv.innerHTML += `<h3 class="text-3xl w-1/3 text-center">${question.question}</h3>`;
        childRowDiv.innerHTML += `<input type="text" class="border border-black rounded-md px-4 py-2" placeholder="Enter your answer here">`;
        targetDiv.appendChild(childRowDiv);
    }
    checkAnswer(question, answer, btn) {
        if (question.correct_answer === answer) {
            btn.classList.toggle("bg-greed-600");
        }
        else {
            btn.classList.toggle("bg-red-600");
            setTimeout(() => {
                btn.classList.toggle("bg-red-600");
            }, 600);
        }
    }
    async start(page, number) {
        if (page === "home") {
            const questions = (await this.api.getQuestions(number ? number + 1 : 10));
            if (questions.length > 1) {
                // Render all but the last question as multiple choice
                questions.slice(0, -1).forEach((question) => {
                    this.renderQuestion("multipleChoice", question);
                });
                // Render the last question as free text
                this.renderQuestion("freeText", questions[questions.length - 1]);
            }
            else if (questions.length === 1) {
                // If only one question is fetched, render it as needed
                this.renderQuestion("multipleChoice", questions[0]); // or "freeText"
            }
            else {
                console.error("No questions fetched");
            }
        }
    }
}
const renderer = new QuestionEngine();
renderer.start("home", 1);
//# sourceMappingURL=main.js.map