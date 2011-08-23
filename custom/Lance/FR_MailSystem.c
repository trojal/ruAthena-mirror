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
//= 21.01.2008 Коррекция перевода [Vorp]
//============================================================
prontera,143,171,3	script	Почта	888,1,1,{
	mes "[Почтальон]";
	mes "Хия! Я быстрейший посыльный в королестве Рун Мидгарде!";
	next;
	mes "[Почтальон]";
	mes "Я могу доставть сообщения вашим друзьям, если они не в игре!";
	next;
	mes "[Почтальон]";
	mes "Хотите попробывать?";
	menu "Да", MENUSYS, "Нет", -;
	close;

MENUSYS:
	next;
	mes "[Почтальон]";
	mes "Что я должен сделать для тя?";
	emotion e_what;
	menu "Проверить почту",L_CHECK,"Послать почту",L_SEND, "Уйти", -;
	next;
	mes "[Почтальон]";
	mes "Приходи ещё!";
	emotion e_no1;
	close;

L_CHECK:
	atcommand strcharinfo(0) + ":@listnewmail";
	menu "Прочесть почту", L_READ, "Проверить всю почту",CHKALLMAIL,"Послать почту",L_SEND, "Удалить почту", DELMAIL, "Назад", MENUSYS;
	close;

CHKALLMAIL:
	atcommand strcharinfo(0) + ":@listmail";
	menu "Прочесть почту", L_READ, "Удалить почту", DELMAIL, "Назад", MENUSYS;
	close;

L_READ:
	next;
	mes "[Почтальон]";
	mes "Скажи мне номер сообщения, что ты хочешь прочесть.";
	input @msgnum;
	next;
	mes "[Почтальон]";
	mes "Вот оно!";
	emotion e_no1;
	atcommand strcharinfo(0) + ":@readmail " + @msgnum;
	menu "Ответить", L_SEND, "Назад", MENUSYS;
	close;

L_SEND:
	next;
	mes "[Почтальон]";
	mes "Кому ты хочешь послать сообщение?";
	input @rcpt$;
	next;
	mes "[Посыльбный Deviruchi]";
	mes "Что ты хочешь написать в письме?";
	input @body$;
	next;
	atcommand strcharinfo(0) + ":@sendmail " + @rcpt$ + " " + @body$;
	mes "[Почтальон]";
	mes "Выполнено!";
	emotion e_no1;
	menu "Отправить другое письмо", L_SEND, "Назад", MENUSYS;
	close;

DELMAIL:
	next;
	mes "[Почтальон]";
	mes "Сообщение под каким номеров ты хочешь удалить?";
	input @msgnum;
	next;
	mes "[Почтальон]";
	mes "Вы уверены, что хотите удалить письмо под номером " + @msgnum + "?";
	menu "Да",-,"Нет",DELMAIL, "Назад", MENUSYS;
	atcommand strcharinfo(0) + ":@deletemail " + @msgnum;
	mes "[Почтальон]";
	mes "Выполнено!";

	emotion e_no1;
	menu "Удалить другое письмо", DELMAIL, "Назад", MENUSYS;
	close;

OnTouch:
	npctalk "Хия! .. Подходите, отправить или получить письмо?";
	emotion e_ok;
	end;
}