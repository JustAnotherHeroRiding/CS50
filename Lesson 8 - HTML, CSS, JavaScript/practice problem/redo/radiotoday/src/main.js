document.addEventListener("DOMContentLoaded", (event) => {
  let paragraph = document.querySelector(".break-after-period");
  let sentences = paragraph.innerText
    .split(".")
    .map((sentence) => sentence.trim() + ".<br><br>")
    .join(" ");
  paragraph.innerHTML = sentences;
});

let lines = [];

function setup() {
  let header = document.querySelector(".header");
  let canvas = createCanvas(header.offsetWidth, header.offsetHeight);
  canvas.parent("p5-canvas"); // Attaching the canvas to your div
  canvas.style("z-index", "-1"); // Ensure the canvas is behind the text
  background(0); // Black background

  // Initialize lines
  for (let i = 0; i < 2; i++) {
    lines.push(new CircuitLine());
  }
}

function draw() {
  clear();
  lines.forEach((line) => {
    line.update();
    line.display();
  });
}

function CircuitLine() {
  this.points = [];
  const pointsCount = random(2, 4); // Number of points for curves

  // Generate random points
  for (let i = 0; i < pointsCount; i++) {
    this.points.push(createVector(random(width), random(height)));
  }

  this.update = function () {
    // Get the header element's bounding box
    let header = document.querySelector("#p5-canvas").getBoundingClientRect();

    // Check if the mouse is within the header element
    if (
      mouseX > header.left &&
      mouseX < header.right &&
      mouseY > header.top &&
      mouseY < header.bottom
    ) {
      let mouse = createVector(mouseX, mouseY);
      this.points[0].lerp(mouse, 0.1); // Move the first point towards the mouse
    }
  };
  this.display = function () {
    noFill();
    stroke("#f77f00"); // Black color for circuit lines
    strokeWeight(2);

    beginShape();
    curveVertex(this.points[0].x, this.points[0].y); // Repeat the first point for a smooth start
    for (let i = 0; i < this.points.length; i++) {
      curveVertex(this.points[i].x, this.points[i].y);
    }
    curveVertex(
      this.points[this.points.length - 1].x,
      this.points[this.points.length - 1].y
    ); // Repeat the last point for a smooth end
    endShape();
  };
}

function windowResized() {
  let header = document.querySelector(".header");
  resizeCanvas(header.offsetWidth, header.offsetHeight);
}
