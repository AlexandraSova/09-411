var
x,y:real;
begin
writeln('������� ���� X');
readln(x);
x:=abs(x);
y:=1+cos(x);
y:=y/(x+1);
y:=ln(y)*exp(x);
writeln('�������� ���� Y');
writeln(y);
end.
