//Music Visualizer of sorts.  Without a mic its no fun (and probably crashes) (your laptop mic works just fine)
//fun with music; an excuse to blast some nice songs for all to hear

//Kind of doesn't answer the homework prompt but who cares right :)


var h = [];
var s = [];
var b = 100;


var microphone;  //why not right
var micLevel;
var scaledMic;
var scaledMic2;
var scaledMic3;

function setup() {
  createCanvas(400, 400);
  colorMode(HSB)
	microphone = new p5.AudioIn();  //probably won't work with fancy soundcards (don't see the need to code a input selector)
	microphone.start();
	for(var index = 0; index < 50; index++)
	{
		h[index] = random(0,255);
		s[index] = random(0, 255);
	}
}

function draw() {

  background(255);
  noStroke();
	micLevel = microphone.getLevel();
	scaledMic = map(micLevel, 0.0, 1.0, width/2, width);
	scaledMic2 = map(micLevel, 0.0, 1.0, height/2, height);
	scaledMic3 = map(micLevel, 0.0, 1.0, 1, 50);

	for(var i = 0; i<50; i++)
	{

		fill(h[i],s[i],b);
		ellipse(scaledMic * random(2),scaledMic2 *random(2),scaledMic3);  //random doesnt really have to be that big but whatever
	}

}
