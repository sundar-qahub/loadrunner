Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");
	web_set_max_html_param_len("9999");
	
	web_reg_find("Text=Welcome to JPetStore 6", "SaveCount=01_Count", LAST);

	lr_start_transaction("09_LoginAndLogout_01_Launch");

	web_url("1",
	"URL={p_url}/", 
	"TargetFrame=", 
	"Resource=0", 
	"Referer=", 
	"Snapshot=t2.inf", 
	"Mode=HTML", 
	LAST);

	if (atoi(lr_eval_string("{01_Count}")) > 0) {
		lr_end_transaction("09_LoginAndLogout_01_Launch", LR_PASS);
	} else {
		lr_end_transaction("09_LoginAndLogout_01_Launch", LR_FAIL);
	}

	lr_think_time(6);

	web_reg_find("Text=Saltwater, Freshwater", "SaveCount=02_Count", LAST);

	//<a href="/actions/Catalog.action;jsessionid=AC0B44DB59C8A6F432F73060EF63454A">
	web_reg_save_param_ex("ParamName=c_jsessionid", "LB=jsessionid=", "RB=\"", "Ordinal=1",  LAST);

	lr_start_transaction("09_LoginAndLogout_02_EnterTheStore");

	web_url("2", 
		"URL={p_url}/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{02_Count}")) > 0) {
		lr_end_transaction("09_LoginAndLogout_02_EnterTheStore",LR_PASS);
	} else {
		lr_end_transaction("09_LoginAndLogout_02_EnterTheStore",LR_FAIL);
	}

	lr_think_time(6);

	web_reg_find("Text=Please enter your username and password.", "SaveCount=03_Count", LAST);

	//<input type="hidden" name="__fp" value="Aad_ECw8vu7kU-fcr01QEekPnipcCKpcVPjdAOanhIn9iy0eC0s_Jk7dSTs_IzgE" />
	web_reg_save_param_ex("ParamName=c_fp", "LB=name=\"__fp\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_sourcepage_03", "LB=name=\"_sourcePage\" value=\"", "RB=\"", "Ordinal=1",  LAST);

	lr_start_transaction("09_LoginAndLogout_03_ClickSignIn");

	web_url("3", 
		"URL={p_url}/actions/Account.action;jsessionid={c_jsessionid}?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{03_Count}")) > 0) {
		lr_end_transaction("09_LoginAndLogout_03_ClickSignIn",LR_PASS);
	} else {
		lr_end_transaction("09_LoginAndLogout_03_ClickSignIn",LR_FAIL);
	}

	lr_think_time(6);

	web_reg_find("Text=Welcome", "SaveCount=04_Count", LAST);

	web_reg_save_param_ex("ParamName=c_sourcepage_04", "LB=name=\"_sourcePage\" value=\"", "RB=\"", "Ordinal=1",  LAST);

	lr_start_transaction("09_LoginAndLogout_04_ClickLogin");

	web_submit_data("4", 
		"Action={p_url}/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Account.action;jsessionid={c_jsessionid}?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=username", "Value={p_username}", ENDITEM, 
		"Name=password", "Value={p_password}", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value={c_sourcepage_03}", ENDITEM, 
		"Name=__fp", "Value={c_fp}", ENDITEM,
		LAST);

	if (atoi(lr_eval_string("{04_Count}")) > 0) {
		lr_end_transaction("09_LoginAndLogout_04_ClickLogin",LR_PASS);
	} else {
		lr_end_transaction("09_LoginAndLogout_04_ClickLogin",LR_FAIL);
	}

	lr_think_time(6);

	web_reg_find("Text=Saltwater, Freshwater", "SaveCount=05_Count", LAST);

	lr_start_transaction("09_LoginAndLogout_05_SignOut");

	web_url("5", 
		"URL={p_url}/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{05_Count}")) > 0) {
		lr_end_transaction("09_LoginAndLogout_05_SignOut",LR_PASS);
	} else {
		lr_end_transaction("09_LoginAndLogout_05_SignOut",LR_FAIL);
	}
	
	lr_think_time(6);
	return 0;
}