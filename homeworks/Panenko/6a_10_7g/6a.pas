program Pr1;

uses
  crt;

var
  k, n, m, tmp: integer; {���� m>=n �� ���������, ������� �� m ��� ������� �� n, � ���� �������, 
  �� ����������� K ��������� ���������� tmp, ������� ���������� ���������� �������� ������ �����.
  m = m/n (��� ��������! m - ����� �����, ������� ����� ������������ ����� ������ real = ������ m. tmp ����������� ��������. �������}
  md: real;

begin
  clrscr;
  tmp := 1;
  writeln('VVedite m and n');
  readln(m, n);
  md := m;
  while md >= n do 
  begin
    if m mod n = 0 then k := tmp;
    md := md / n;
    inc(tmp);
  end;
  writeln(k);
  readln();
end.