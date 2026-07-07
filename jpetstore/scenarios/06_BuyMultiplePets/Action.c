Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");
	web_set_max_html_param_len("9999");

	web_reg_find("Text=Welcome to JPetStore 6", "SaveCount=01_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_01_Launch");
	
	web_url("1", 
	"URL={p_url}/", 
	"TargetFrame=", 
	"Resource=0", 
	"Referer=",
	"Snapshot=t2.inf", 
	"Mode=HTML", 
	LAST);

	if (atoi(lr_eval_string("{01_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_01_Launch",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_01_Launch",LR_FAIL);
	}
	
	lr_think_time(3);

	web_reg_find("Text=Saltwater, Freshwater", "SaveCount=02_Count", LAST);
	
	//<a href="/actions/Catalog.action;jsessionid=AC0B44DB59C8A6F432F73060EF63454A">
	web_reg_save_param_ex("ParamName=c_jsessionid", "LB=jsessionid=", "RB=\"", "Ordinal=1",  LAST);
	
	lr_start_transaction("06_BuyMultiplePets_02_EnterTheStore");

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
		lr_end_transaction("06_BuyMultiplePets_02_EnterTheStore",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_02_EnterTheStore",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Please enter your username and password.", "SaveCount=03_Count", LAST);
	
	//<input type="hidden" name="__fp" value="Aad_ECw8vu7kU-fcr01QEekPnipcCKpcVPjdAOanhIn9iy0eC0s_Jk7dSTs_IzgE" />
	web_reg_save_param_ex("ParamName=c_fp", "LB=name=\"__fp\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_sourcepage_03", "LB=name=\"_sourcePage\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	
	lr_start_transaction("06_BuyMultiplePets_03_ClickSignIn");

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
		lr_end_transaction("06_BuyMultiplePets_03_ClickSignIn",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_03_ClickSignIn",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Welcome", "SaveCount=04_Count", LAST);
	
	lr_start_transaction("06_BuyMultiplePets_04_ClickLogin");

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
		lr_end_transaction("06_BuyMultiplePets_04_ClickLogin",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_04_ClickLogin",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Product ID", "SaveCount=05_Count", LAST);

	lr_start_transaction("06_BuyMultiplePets_05_ClickPet1");

	web_url("5", 
		"URL={p_url}/actions/Catalog.action?viewCategory=&categoryId={p_pet1}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	if (atoi(lr_eval_string("{05_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_05_ClickPet1",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_05_ClickPet1",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Item ID", "SaveCount=06_Count", LAST);

	lr_start_transaction("06_BuyMultiplePets_06_SelectPet1Product");

	web_url("6", 
		"URL={p_url}/actions/Catalog.action?viewProduct=&productId={p_productID1}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action?viewCategory=&categoryId={p_pet1}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{06_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_06_SelectPet1Product",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_06_SelectPet1Product",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Quantity", "SaveCount=07_Count", LAST);
	
	web_reg_save_param_ex("ParamName=c_sourcepage_07", "LB=name=\"_sourcePage\" value=\"", "RB=\"", "Ordinal=1",  LAST);

	lr_start_transaction("06_BuyMultiplePets_07_ClickAddToCartPet1Item");

	web_url("7", 
		"URL={p_url}/actions/Cart.action?addItemToCart=&workingItemId={p_itemID1}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action?viewProduct=&productId={p_productID1}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	if (atoi(lr_eval_string("{07_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_07_ClickAddToCartPet1Item",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_07_ClickAddToCartPet1Item",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Quantity", "SaveCount=08_Count", LAST);
	
	lr_start_transaction("06_BuyMultiplePets_08_UpdateRandomQuantityAndUpdateCart");

	web_submit_data("8", 
		"Action={p_url}/actions/Cart.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Cart.action?addItemToCart=&workingItemId={p_itemID1}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name={p_itemID1}", "Value={p_quantity1}", ENDITEM, 
		"Name=updateCartQuantities", "Value=Update Cart", ENDITEM, 
		"Name=_sourcePage", "Value={c_sourcepage_07}", ENDITEM, 
		"Name=__fp", "Value={c_fp}", ENDITEM, 
		LAST);

	if (atoi(lr_eval_string("{08_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_08_UpdateRandomQuantityAndUpdateCart",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_08_UpdateRandomQuantityAndUpdateCart",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Saltwater, Freshwater", "SaveCount=09_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_09_ReturnToMainMenu");

	web_url("9", 
		"URL={p_url}/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Cart.action", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{09_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_09_ReturnToMainMenu",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_09_ReturnToMainMenu",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Product ID", "SaveCount=10_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_10_SelectPet2");

	web_url("10", 
		"URL={p_url}/actions/Catalog.action?viewCategory=&categoryId={p_pet2}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{10_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_10_SelectPet2",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_10_SelectPet2",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Item ID", "SaveCount=11_Count", LAST);

	lr_start_transaction("06_BuyMultiplePets_11_SelectPet2Product");

	web_url("11", 
		"URL={p_url}/actions/Catalog.action?viewProduct=&productId={p_productID2}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action?viewCategory=&categoryId={p_pet2}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{11_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_11_SelectPet2Product",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_11_SelectPet2Product",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Quantity", "SaveCount=12_Count", LAST);
	web_reg_save_param_ex("ParamName=c_sourcepage_12", "LB=name=\"_sourcePage\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	lr_start_transaction("06_BuyMultiplePets_12_AddToCartPet2Item");

	web_url("12", 
		"URL={p_url}/actions/Cart.action?addItemToCart=&workingItemId={p_itemID2}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Catalog.action?viewProduct=&productId={p_productID2}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{12_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_12_AddToCartPet2Item",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_12_AddToCartPet2Item",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Quantity", "SaveCount=13_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_13_UpdateRandomQuanityPet2ItemAndUpdateCart");

	web_submit_data("13", 
		"Action={p_url}/actions/Cart.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Cart.action?addItemToCart=&workingItemId={p_itemID2}", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name={p_itemID1}", "Value={p_quantity1}", ENDITEM, 
		"Name={p_itemID2}", "Value={p_quantity2}", ENDITEM, 
		"Name=updateCartQuantities", "Value=Update Cart", ENDITEM, 
		"Name=_sourcePage", "Value={c_sourcepage_12}", ENDITEM, 
		"Name=__fp", "Value={c_fp}", ENDITEM, 
		LAST);

	if (atoi(lr_eval_string("{13_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_13_UpdateRandomQuanityPet2ItemAndUpdateCart",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_13_UpdateRandomQuanityPet2ItemAndUpdateCart",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Payment Details", "SaveCount=14_Count", LAST);
	
	web_reg_save_param_ex("ParamName=c_sourcepage_14", "LB=name=\"_sourcePage\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_cardType", "LB=selected=\"selected\">", "RB=</option>", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_cardNumber", 
	        "LB=input name=\"order.creditCard\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_cardExpiry", 
	        "LB=input name=\"order.expiryDate\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_firstName", 
	        "LB=input name=\"order.billToFirstName\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_lastName", 
	        "LB=input name=\"order.billToLastName\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_address1", 
	        "LB=name=\"order.billAddress1\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_city", 
	        "LB=input name=\"order.billCity\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_state", 
	        "LB=name=\"order.billState\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_zip", 
	        "LB=name=\"order.billZip\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	web_reg_save_param_ex("ParamName=c_country", 
	        "LB=name=\"order.billCountry\" type=\"text\" value=\"", "RB=\"", "Ordinal=1",  LAST);
	
	lr_start_transaction("06_BuyMultiplePets_14_ProceedToCheckOut");

	web_url("14", 
		"URL={p_url}/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Cart.action", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{14_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_14_ProceedToCheckOut",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_14_ProceedToCheckOut",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Please confirm the information below", "SaveCount=15_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_15_EnterPaymentDetailsAndContinue");

	web_submit_data("15", 
		"Action={p_url}/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Order.action?newOrderForm=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=order.cardType", "Value={c_cardType}", ENDITEM, 
		"Name=order.creditCard", "Value={c_cardNumber}", ENDITEM, 
		"Name=order.expiryDate", "Value={c_cardExpiry}", ENDITEM, 
		"Name=order.billToFirstName", "Value={c_firstName}", ENDITEM, 
		"Name=order.billToLastName", "Value={c_lastName}", ENDITEM, 
		"Name=order.billAddress1", "Value={c_address1}", ENDITEM, 
		"Name=order.billAddress2", "Value=", ENDITEM, 
		"Name=order.billCity", "Value={c_city}", ENDITEM, 
		"Name=order.billState", "Value={c_state}", ENDITEM, 
		"Name=order.billZip", "Value={c_zip}", ENDITEM, 
		"Name=order.billCountry", "Value={c_country}", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value={c_sourcepage_14}", ENDITEM, 
		"Name=__fp", "Value={c_fp}", ENDITEM, 
		LAST);

	if (atoi(lr_eval_string("{15_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_15_EnterPaymentDetailsAndContinue",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_15_EnterPaymentDetailsAndContinue",LR_FAIL);
	}

	lr_think_time(3);

	web_reg_find("Text=Thank you, your order has been submitted.", "SaveCount=16_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_16_ConfirmTheOrder");

	web_url("16", 
		"URL={p_url}/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Order.action", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{16_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_16_ConfirmTheOrder",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_16_ConfirmTheOrder",LR_FAIL);
	}

	lr_think_time(3);
	
	web_reg_find("Text=Saltwater, Freshwater", "SaveCount=17_Count", LAST);
	lr_start_transaction("06_BuyMultiplePets_17_SignOut");

	web_url("17", 
		"URL={p_url}/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={p_url}/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	if (atoi(lr_eval_string("{17_Count}")) > 0) {
		lr_end_transaction("06_BuyMultiplePets_17_SignOut",LR_PASS);
	} else {
		lr_end_transaction("06_BuyMultiplePets_17_SignOut",LR_FAIL);
	}

	lr_think_time(3);
	
	return 0;
}