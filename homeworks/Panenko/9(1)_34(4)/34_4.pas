var 
  n,k,y,i,j,sum,proz:real;

begin
  writeln('������� n');
  readln(n);
  
  writeln('������� k');
  readln(k);
  
  writeln('������� y');
  readln(y);
  
  i:=2;
  proz:=1;
  
  while i<=n do begin
    j:=0;
    sum:=0;
    while j<=k do begin
      sum:= sum + ln(i + cos(j * y));
      j:=j + 1;
    end;
    proz:= proz * sum;
    i:= i + 1;
  end;
  
  writeln(proz);
  
end.
    
      
  