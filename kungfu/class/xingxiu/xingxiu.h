// xingxiu.h

//int welcome(object ob)
int permit_recruit(object ob)
{
	if( ob->query("detach/星宿派") || ob->query("betrayer/星宿派") )
	{
		command("say 哈哈！想来想去都是我们星宿派好吧！");
		return 0;
	}
/*
	if( ob->query("betrayer/times") )
	{
		command("say 没关系，你虽然判过几次师，不过最后终于弃暗投明，可喜可贺！");
		return 0;
	}
*/if( ob->query("betrayer/times") )
	{
		command("say 判师dog，想来玷污我大星宿？还不快滚！！");
		return 0;
	}
	
		if( ob->query("family/family_name") &&
	    ob->query("family/family_name") != "星宿派" )
	{
		command("say 你已有名师指点，为何还要来本派"
			"莫非你要判师不成？");
		return 0;
	}
	if( ob->query("family/family_name") &&
	    ob->query("family/family_name") != "星宿派" )
	{
		command("say 呵呵，好啊！" + ob->query("family/family_name") +
			"算什么！");
		return 0;
	}

	return 1;
}
