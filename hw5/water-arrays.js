//Enjoyed the steady drips more than sparadic ones, but could have added an xSpeed array a x displacement in a similar vein to y for a more forceful spigot

var x = 230;
var y = 220;

var ySpeed = [];

function setup() {
  createCanvas(400, 400);
  colorMode(HSB)
	for(var i = 0; i < 25; i++)
	{
		ySpeed[i] = random (1, 30);
	}
}

function draw() {
  background(0);
  noStroke();

  // draw pipe
  rect(0, 200, x, 20);

  // draw drip
	for(var drips = 0; drips < 25; drips++)
	{
  	ellipse(x, y, 10);

  	y = y + ySpeed[drips]

  	// if invisible for a full “height” amount…
  	if (y > height*2) {
    // reset
    y = 220;
		}
	}

}
