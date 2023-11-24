document.addEventListener("DOMContentLoaded", (event) => {
  let paragraph = document.querySelector(".break-after-period");
  let sentences = paragraph.innerText
    .split(".")
    .map((sentence) => sentence.trim() + ".<br><br>")
    .join(" ");
  paragraph.innerHTML = sentences;
});
