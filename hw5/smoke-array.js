//This code is super broken but I kind of dig the results regardless

var x = [];
var y = [];
var r = 0;
var xVar = [];

function setup() {
  createCanvas(400, 400);
	for(var i = 0; i < 100; i++)
	{
		x[i] = 210;
		y[i] = 290;
		xVar[i] = random(-20, 20);
	}
}

function draw() {
  background(0);
  noStroke();

  // draw smokestack
  fill(255);
  rect(195, height, 30, -100);

  // save graphics state
  push();
  // darker as it gets closer to 0

  // rotate r around (x,y)

  // draw rectangle
	for(var i = 0; i <100; i ++)
	{
		fill(y[i]);
		translate(x[i], y[i]);
  	rotate(r);
		 rect(-10, -10, 20, 20);
		y[i] -= 0.0003;
		x[i] -= xVar[i]* 0.0003;
		 if (y[i] < -150) {
    y[i] = 290;
		x[i] = 210;
  }
	}

	//rect(-15, -10, 20, 20);
  // reset rotation and translation
  pop();

  // up 3 pixels


  // rotate 0.05 radians ~= 2.8 degrees per frame
  r += 0.05

  // if reach past the top a bunch

}
