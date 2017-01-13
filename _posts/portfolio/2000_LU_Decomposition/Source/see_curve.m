load output.txt

x=output(:,2);
y1=output(:,3);
y2=output(:,4);
y3=output(:,5);
y4=output(:,6);

plot(x,y1,'m.')
hold on
plot(x,y2,'c.')
plot(x,y3,'r.')
plot(x,y4,'.')
grid on

plot(x,y1)
plot(x,y2)
plot(x,y3)
plot(x,y4)
