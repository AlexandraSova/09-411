program zad51;

var
  m, k: integer;
  p, n: real;

begin
  {Opredelyem min k takoe chto m<n^k}
  read(m, n);
  k := 0;
  repeat
    p := round(power(n, k));
    k := k + 1;
  until p > m;
  k := round(ln(p) / ln(n));
  write(k);
end.
