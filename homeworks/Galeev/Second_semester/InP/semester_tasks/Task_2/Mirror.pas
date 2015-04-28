program mirror;

uses UTM, UDLL;

var
  TM: tTM;
  
BEGIN

  initList(TM.list);
  pushBack(TM.list, '0');
  pushBack(TM.list, '0');
  pushBack(TM.list, '0');
  pushBack(TM.list, '0');
  pushBack(TM.list, '1');
  pushBack(TM.list, '0');
  pushBack(TM.list, '_');
  
  TM.tr[1, '0'] := state('0', R, 1);// q1
  TM.tr[1, '1'] := state('1', R, 1);// � ���� ��������� ������ ������� �� ����� �����,
  TM.tr[1, '_'] := state('_', L, 2);// �� ����� �������� ���������
  
  TM.tr[2, '0'] := state('0', L, 4);// q2
  TM.tr[2, '1'] := state('1', L, 3);// ������ � ���� ��������� �������� ������������ ������� � ����� �����
  TM.tr[2, 'o'] := state('o', L, 11);// o - ���������� 0
  TM.tr[2, '!'] := state('!', L, 11);// ! - ���������� 1
  
  TM.tr[3, '0'] := state('0', L, 3);// q3
  TM.tr[3, '1'] := state('1', L, 3);// � ���������� q3 � q4 ������ ���� � ������ �����
  TM.tr[3, 'o'] := state('o', R, 5);// ��� �� ������� ����������� �������
  TM.tr[3, '!'] := state('!', R, 5);// � ��������� q3 � ������ ������ - 1
  TM.tr[3, '_'] := state('_', R, 5);// � ��������� q4 - 0
  
  TM.tr[4, '0'] := state('0', L, 4);// q4
  TM.tr[4, '1'] := state('1', L, 4);
  TM.tr[4, 'o'] := state('o', R, 6);
  TM.tr[4, '!'] := state('!', R, 6);
  TM.tr[4, '_'] := state('_', R, 6);
  
  TM.tr[5, '0'] := state('!', R, 8);// q5
  TM.tr[5, '1'] := state('!', R, 7);// � ��������� q5 � q6 ������ ���������� � ������ ������������� ��������
  TM.tr[5, '!'] := state('!', N, 11);// � �������� ������ �� ������� ������
  
  TM.tr[6, '0'] := state('o', R, 8);// q6
  TM.tr[6, '1'] := state('o', R, 7);
  TM.tr[6, 'o'] := state('o', N, 11);
  
  TM.tr[7, '0'] := state('0', R, 7);// q7
  TM.tr[7, '1'] := state('1', R, 7);// ��������� q7 � q8 ���������� ���������� q3 � q4
  TM.tr[7, 'o'] := state('o', L, 9);// �� ������ ��������� � ������ �������
  TM.tr[7, '!'] := state('!', L, 9);
  TM.tr[7, '_'] := state('_', L, 9);
  
  TM.tr[8, '0'] := state('0', R, 8);// q8
  TM.tr[8, '1'] := state('1', R, 8);
  TM.tr[8, 'o'] := state('o', L, 10);
  TM.tr[8, '!'] := state('!', L, 10);
  TM.tr[8, '_'] := state('_', L, 10);
  
  TM.tr[9, '0'] := state('!', L, 2);// q9
  TM.tr[9, '1'] := state('!', L, 2);// ��������� q9 � q10 ���������� q5 � q6,
  TM.tr[9, '!'] := state('!', N, 11);// � q9 � q10 ������ ����� ������� � ��������� q2, ����� ������ ���� ������
  
  TM.tr[10, '0'] := state('o', L, 2);// q10
  TM.tr[10, '1'] := state('o', L, 2);
  TM.tr[10, 'o'] := state('o', N, 11);
  
  TM.tr[11, 'o'] := state('o', L, 11);// q11
  TM.tr[11, '!'] := state('!', L, 11);// ������� ������������ � ������ �����
  TM.tr[11, '_'] := state('_', R, 12);
  
  TM.tr[12, 'o'] := state('0', R, 12);// q12
  TM.tr[12, '!'] := state('1', R, 12);// ������ �����
  TM.tr[12, '_'] := state('_', N, 0);
  
  startTM(TM);
  delete(TM.list, TM.list.size);
  
  print(TM.list);
  
END.