document.addEventListener("DOMContentLoaded", (event) => {
  let paragraph = document.querySelector(".break-after-period");
  let sentences = paragraph.innerText
    .split(".")
    .map((sentence) => sentence.trim() + ".<br><br>")
    .join(" ");
  paragraph.innerHTML = sentences;

  document.getElementById("hamburger").addEventListener("click", function () {
    var menu = document.getElementById("menuItems");
    if (menu.classList.contains("hidden")) {
      menu.classList.remove("hidden");
    } else {
      menu.classList.add("hidden");
    }
  });
});
