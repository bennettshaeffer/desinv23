//A weird, 'arythmic' semi-binary pattern sequencer built into a pseudo-brutalist art style

function bennettPatch(x, y) {

  background(253);

  noFill();
  noSmooth();
  stroke(100);
  h = 2;

  fill(5);
  rect(300, 300, -300, -150);
  fill('rgba(255, 100, 45, 1)');
	rect(0, 0, 300, 150);

  for (var i = 300; i >=0; i = i - 50)
  {
    if(i-50 > 0)
    {
      if(h%2 == 0)
      {
        if(i<150)
        {
          fill(0);
    			rect(i,i-25, -100, -25);

      		fill(255);
      		rect(i,i,-50,-25);
        }

        else
        {
     			fill(255);
    			rect(i,i-25, -100, -25);

      		fill(0);
      		rect(i,i,-50,-25);
        }
      }
      else
      {
        if(i<150)
        {
        	fill(220);
      		rect(i,i,-50,-25);
        	fill(4);
    			rect(i,i-25, -100, -25);
        }
        else
        {
          fill(4);
      		rect(i,i-25,-100,-25);
        	fill(220);
    			rect(i,i, -50, -25);
        }
      }
    }
    else
    {
     	fill(0);
      rect(i, i, -50, -25);
      i = 0;
    }
    h = h+1;
  }

}
bennettPatch(0, 0); // draw patch at upper-left
