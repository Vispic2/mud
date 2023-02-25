// zhangyuan.c 掌园道长
// By Lgg,1998.10

inherit NPC;

void create()
{
	set_name("掌园道长", ({"zhangyuan"}));
	set("gender", "男性");
	set("age", 52);
	set("class", "taoist");
	set("long",
		"他本是服侍重阳祖师的童子，现在年纪大了。重阳祖师见他忠\n"
		"心耿耿，就分配他一个闲差，到小花园来打理花木。\n");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 18);
	set("int", 18);
	set("con", 20);
	set("dex", 21);

	set("qi", 500);
	set("max_qi", 500);
	set("jing", 350);
	set("max_jing", 350);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 0);

	set("combat_exp", 20000);
	set("score", 15000);

	set_skill("force", 40);
	set_skill("quanzhen-xinfa", 40);
	set_skill("sword", 40);
	set_skill("quanzhen-jian",40);
	set_skill("dodge", 50);
	set_skill("jinyan-gong", 40);
	set_skill("parry", 50);
	set_skill("unarmed",50);
	set_skill("strike",50);
	set_skill("haotian-zhang", 50);
	set_skill("literate",40);
	set_skill("taoism",30);

	map_skill("force", "quanzhen-xinfa");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	prepare_skill("strike", "haotian-zhang");

	create_family("全真教", 4, "弟子");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
