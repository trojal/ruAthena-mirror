//(=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=)
//(       (c)2005 RagMods Modification Team presents        )
//(       ______  __    __                                  )
//(      /\  _  \/\ \__/\ \                     v 1.00.00   )
//(    __\ \ \_\ \ \ ,_\ \ \___      __    ___      __      )
//(  /'__`\ \  __ \ \ \/\ \  _ `\  /'__`\/' _ `\  /'__`\    )
//( /\  __/\ \ \/\ \ \ \_\ \ \ \ \/\  __//\ \/\ \/\ \_\.\_  )
//( \ \____\\ \_\ \_\ \__\\ \_\ \_\ \____\ \_\ \_\ \__/.\_\ )
//(  \/____/ \/_/\/_/\/__/ \/_/\/_/\/____/\/_/\/_/\/__/\/_/ )
//(                                                         )
//(            -- [s] [c] [r] [i] [p] [t] [s] --            )
//(   _   _   _   _   _   _   _     _   _   _   _   _   _   )
//(  / \ / \ / \ / \ / \ / \ / \   / \ / \ / \ / \ / \ / \  )
//( ( e | n | g | l | i | s | h ) ( A | t | h | e | n | a ) )
//(  \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ \_/ \_/ \_/ \_/ \_/  )
//(                                                         )
//(  Advanced Fusion Maps (c) 2003-2005 The Fusion Project  )
//(=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=)
//===== eAthena Script ======================================
//= Mail System (using built in mail function)
//===========================================================
//===== By ==================================================
//= [Lance]
//===== Version =============================================
//= 1.0
//===== Compatible With =====================================
//= Any flavours of Athena SQL
//===== Description =========================================
//= Allows players to send and receive mails without GM lvl.
//===== Comments ============================================
//= 1.0 - Initial release                             [Lance]
//===== Translated into Russian: =============================
//= 21.01.2008 ��������� �������� [Vorp]
//============================================================
prontera,143,171,3	script	�����	888,1,1,{
	mes "[���������]";
	mes "���! � ���������� ��������� � ���������� ��� ��������!";
	next;
	mes "[���������]";
	mes "� ���� �������� ��������� ����� �������, ���� ��� �� � ����!";
	next;
	mes "[���������]";
	mes "������ �����������?";
	menu "��", MENUSYS, "���", -;
	close;

MENUSYS:
	next;
	mes "[���������]";
	mes "��� � ������ ������� ��� ��?";
	emotion e_what;
	menu "��������� �����",L_CHECK,"������� �����",L_SEND, "����", -;
	next;
	mes "[���������]";
	mes "������� ���!";
	emotion e_no1;
	close;

L_CHECK:
	atcommand strcharinfo(0) + ":@listnewmail";
	menu "�������� �����", L_READ, "��������� ��� �����",CHKALLMAIL,"������� �����",L_SEND, "������� �����", DELMAIL, "�����", MENUSYS;
	close;

CHKALLMAIL:
	atcommand strcharinfo(0) + ":@listmail";
	menu "�������� �����", L_READ, "������� �����", DELMAIL, "�����", MENUSYS;
	close;

L_READ:
	next;
	mes "[���������]";
	mes "����� ��� ����� ���������, ��� �� ������ ��������.";
	input @msgnum;
	next;
	mes "[���������]";
	mes "��� ���!";
	emotion e_no1;
	atcommand strcharinfo(0) + ":@readmail " + @msgnum;
	menu "��������", L_SEND, "�����", MENUSYS;
	close;

L_SEND:
	next;
	mes "[���������]";
	mes "���� �� ������ ������� ���������?";
	input @rcpt$;
	next;
	mes "[���������� Deviruchi]";
	mes "��� �� ������ �������� � ������?";
	input @body$;
	next;
	atcommand strcharinfo(0) + ":@sendmail " + @rcpt$ + " " + @body$;
	mes "[���������]";
	mes "���������!";
	emotion e_no1;
	menu "��������� ������ ������", L_SEND, "�����", MENUSYS;
	close;

DELMAIL:
	next;
	mes "[���������]";
	mes "��������� ��� ����� ������� �� ������ �������?";
	input @msgnum;
	next;
	mes "[���������]";
	mes "�� �������, ��� ������ ������� ������ ��� ������� " + @msgnum + "?";
	menu "��",-,"���",DELMAIL, "�����", MENUSYS;
	atcommand strcharinfo(0) + ":@deletemail " + @msgnum;
	mes "[���������]";
	mes "���������!";

	emotion e_no1;
	menu "������� ������ ������", DELMAIL, "�����", MENUSYS;
	close;

OnTouch:
	npctalk "���! .. ���������, ��������� ��� �������� ������?";
	emotion e_ok;
	end;
}