/*
Glitchy mess of circles

kind of became super morbid but whatever

treat it like a simulation of the futility of life

don't run if you are epileptic!!!!!!
*/

var circles = [];

function setup() {
  createCanvas(400, 400);
  colorMode(HSB);

  for (var index = 0; index < 100; index = index + 1) {
    // new "circle" object, with x, y, xd, yd, and c properties:
    circles[index] = {
      x: width / 2,
      y: height / 2,
      xd: random(-2, 2),
      yd: random(-2, 2),
      c: color(random(360), 60, 100),
      r: random(5,15),
      isDead: 0  //gives these circles mortality for some reason
    }
  }
}

function draw() {
  noStroke();

  for (var index = 0; index < 100; index = index + 1) {
    // get circle object
    var circle = circles[index];

    // draw it
    fill(circle.c);
    ellipse(circle.x, circle.y, circle.r);

    // move it according to direction
    circle.x = circle.x + circle.xd;
    circle.y = circle.y + circle.yd;

    // check boundaries and update directions
    if (circle.x > width || circle.x < 0  && circle.r >= 1) {
      circle.xd = -circle.xd;
			circle.r = circle.r - 1;
			background(255);
    }
    if (circle.y > height || circle.y < 0  && circle.r >= 1) {
      circle.yd = -circle.yd;
			circle.r = circle.r - 1;
			background(255);

    }
    if(circle.r < 1 && circle.isDead == 0)	//get rid of those circles
    {
	circle.r = 0;
	circle.x =width/2;
	circle.y= height/2;
	circle.xd = 0;
	circle.yd = 0;
	circle.isDead = 1;
	background(0);  //to mourn the death of a circle (at least for that frame/until another circle creeps closer to death)
    }
  }
}
