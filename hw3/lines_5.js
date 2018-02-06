var count = 1;
while (count <= width/2)
{
 	line(width/2-count, count, width/2+count , count);
  count = count+ 10
}
count = 1;
line(0, height/2, width, height/2)
while (count < width/2)
{
 	line(width/2-count, height-count, width/2+count , height-count);
  count = count+ 10
}
