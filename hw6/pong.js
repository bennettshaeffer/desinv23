/*
pong?

will explain how to play at the end of the code.  The game
functions best if neither players knows  what is going on at all

*/



var mic;
var randomDir;
var maxScore = 25;


var puck = {
  x: 200,
  y: 200,
  xSpeed: 4,
  ySpeed: -4,
  r: 15
};
var edgeOffset = 20;

var player1 = {
  x: edgeOffset,
  y: 200,
  ht: 50,
  wd: 10,
	score: 0
};

var player2 = {
  x: 400-edgeOffset,
  y: 200,
  ht: 50,
  wd: 10,
	score: 0
};


function setup() {
  createCanvas(400, 400);
	mic = new p5.AudioIn();
	mic.start();
}

function draw() {
  background(255);

	micLevel = mic.getLevel();	//Lets make this game impossible
	randomDir = random(0,100);


	textSize(48);
	text(player1.score, 48, height/4);
	text(player2.score, width/2+96, height/4);

  // draw puck
  ellipse(puck.x, puck.y, puck.r*2);

  // move puck
  if (puck.y < puck.r || puck.y > height - puck.r) {
    puck.ySpeed = -puck.ySpeed;

		if(randomDir >= 50)  //makes the game much more exciting
		{
			puck.xSpeed = map(micLevel, 0, 1, 1, 15);
		}
		else
		{
			puck.xSpeed = map(micLevel, 0, 1, -1, -15);
		}

  }

  puck.x += puck.xSpeed;
  puck.y += puck.ySpeed;

  // draw paddles
  rect(player1.x, player1.y, player1.wd, player1.ht);
  rect(player2.x-player2.wd, player2.y, player2.wd, player2.ht);

  // paddle movement
  if (player1.paddleDown && ! player1.paddleUp) {
    player1.y += 5;
  }
  if (player1.paddleUp && ! player1.paddleDown) {
    player1.y -= 5;
  }

  if (player2.paddleDown && ! player2.paddleUp) {
    player2.y += 5;
  }
  if (player2.paddleUp && ! player2.paddleDown) {
    player2.y -= 5;
  }

  // don't let paddles outside of the play area
  player1.y = constrain(player1.y, 0, height-player1.ht-1);
  player2.y = constrain(player2.y, 0, height-player2.ht-1);

  // bounce puck on paddles -- player 1 -- based on x-coordinate
  if (puck.x - puck.r < player1.x + player1.wd) {
    // check if puck is within paddle height...
    if (puck.y > player1.y && puck.y < player1.y + player1.ht) {
      puck.xSpeed = abs(puck.xSpeed);
			player1.score += floor(map(micLevel, 0, 1, 1, 10));
    } else {
			puck.x= 200;
			puck.y= 200;
      player2.score += floor(map(micLevel, 0, 1, 1, 10));
    }
  }

  // bounce puck on paddles -- player 2 -- based on x-coordinate
  if (puck.x + puck.r > player2.x - player2.wd) {
    // check if puck is within paddle height...
    if (puck.y > player2.y && puck.y < player2.y + player2.ht) {
      puck.xSpeed = -abs(puck.xSpeed);
			player2.score += floor(map(micLevel, 0, 1, 1, 10));
    } else {
			puck.x= 200;
			puck.y= 200;
			player1.score += floor(map(micLevel, 0, 1, 1, 10));
    }
  }
	if(player1.score >= maxScore)
	{
		background(255);
		textSize(12);
		text("player one was louder", 0, height/2);
		return false;

	}
	else if(player2.score >= maxScore)
	{
		background(255);
		textSize(12);
		text("player two was louder",0, height/2);
		return false;

	}
}

// keyboard input
function keyPressed() {
  print(key);
  if (key == 'A') {
    player1.paddleDown = true;
  } else if (key == 'Q') {
    player1.paddleUp = true;
  }

  if (keyCode == DOWN_ARROW) {
    player2.paddleDown = true;
  } else if (keyCode == UP_ARROW) {
    player2.paddleUp = true;
  }
}

function keyReleased() {
  if (key == 'A') {
    player1.paddleDown = false;
  } else if (key == 'Q') {
    player1.paddleUp = false;
  }

  if (keyCode == DOWN_ARROW) {
    player2.paddleDown = false;
  } else if (keyCode == UP_ARROW) {
    player2.paddleUp = false;
  }
}



/*
Instructions:
	the game works via the inbuilt mic in your computer

	every time the ball hits a wall, it pings off in a random direction at the speed of
	however loud the environment is where the game is being played

	scoring funtions based off of sound too

	if the player successfully hits the ball, the amplitude of the room will be added to their point total

	if the player fails to hit the ball, the amplitude is given to the other players score

	probably the best way to play this game is to yell if you know you are going to hit the ball,
	or yell if you think your opponent is not going to hit the ball

	its probably easy to cheat at this but at the same time in order to cheat you still have to scream at your computer,
	so is it really worth it at that point?

	I recommend playing this game in a very public space
*/
