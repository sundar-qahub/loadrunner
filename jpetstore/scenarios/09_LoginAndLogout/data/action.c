Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("1_Launch");

	lr_end_transaction("1_Launch",LR_AUTO);

	lr_start_transaction("2_EnterTheStore");

	web_url("Catalog.action", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("2_EnterTheStore",LR_AUTO);

	lr_think_time(6);

	lr_start_transaction("3_ClickSignIn");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=5BE48DB9C4E58DCED62A7BBB6808EB67?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_ClickSignIn",LR_AUTO);

	lr_start_transaction("4_ClickLogin");

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=5BE48DB9C4E58DCED62A7BBB6808EB67?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=username", "Value=perfuser01", ENDITEM, 
		"Name=password", "Value=perfuser@01", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=0nmVCszIF0GrBfbSQgJOdYjcUzEhHjdk6i4Iy2Yt0JqhhgOFX3DjJQEnk55Vxo216WmRe7YMf0XY_cQ2OlXHDG7TDQmI-0EbU4v5mw7eCpM=", ENDITEM, 
		"Name=__fp", "Value=Eo3pW4H5nMXtXt1WdHLtzXmPNCUU7mkbFruqjPx8IFR1zT6oSgPibgHNX12SUE0g", ENDITEM, 
		LAST);

	lr_end_transaction("4_ClickLogin",LR_AUTO);

	lr_think_time(56);

	lr_start_transaction("5_EnterProductInSearchBox");

	web_submit_data("Catalog.action_2", 
		"Action=https://petstore.octoperf.com/actions/Catalog.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=keyword", "Value=Angelfish", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		"Name=_sourcePage", "Value=wTmWxp9crDDR053yqYz-PpU3Uk1jZVy5XbyiIwIY50A9vqRksHUZChPBZSlVwoU7m2A3iQTT5o4sRE5qT9fDLB5BZY-z7EcO", ENDITEM, 
		"Name=__fp", "Value=Eikfa1IT-2xYGRaTESg1Eq-NzJY-9hgsrAXXO_F0tbizjnfN80PtkH74aO9aPduu", ENDITEM, 
		LAST);

	lr_end_transaction("5_EnterProductInSearchBox",LR_AUTO);

	lr_think_time(41);

	lr_start_transaction("6_SelectProductFromSearchResult");

	web_url("Salt Water fish from Australia", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("6_SelectProductFromSearchResult",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("7_AddPetitemToCart");

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-01", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("7_AddPetitemToCart",LR_AUTO);

	lr_think_time(39);

	lr_start_transaction("8_UpdateRandomQuantityAndUpdateCart");

	web_submit_data("Cart.action", 
		"Action=https://petstore.octoperf.com/actions/Cart.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-2", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=EST-2", "Value=4", ENDITEM, 
		"Name=updateCartQuantities", "Value=Update Cart", ENDITEM, 
		"Name=_sourcePage", "Value=vAB9aYEkEzcsdhpiHaGJ3Fiy2rtS2N9evVw_aPlIY0kUNJ1qD42b_KW5yIAXkZZVUO3xorHA8HrW6MrfRTGtXvkTfGSzLr5H", ENDITEM, 
		"Name=__fp", "Value=7U-fqRSOTXWFaC1SFXc5Te8lOyrt6iq1kYuPF_N4dyJa2N9QRaKdCx82jIVx1S4w", ENDITEM, 
		LAST);

	lr_end_transaction("8_UpdateRandomQuantityAndUpdateCart",LR_AUTO);

	lr_think_time(32);

	lr_start_transaction("9_ProceedToCheckout");

	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("9_ProceedToCheckout",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("10_EnterPaymentDetailsAndContinue");

	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=order.cardType", "Value=Visa", ENDITEM, 
		"Name=order.creditCard", "Value=999 9999 9999 9999", ENDITEM, 
		"Name=order.expiryDate", "Value=12/03", ENDITEM, 
		"Name=order.billToFirstName", "Value=perf", ENDITEM, 
		"Name=order.billToLastName", "Value=user", ENDITEM, 
		"Name=order.billAddress1", "Value=123 joe street", ENDITEM, 
		"Name=order.billAddress2", "Value=", ENDITEM, 
		"Name=order.billCity", "Value=NewYork", ENDITEM, 
		"Name=order.billState", "Value=NY", ENDITEM, 
		"Name=order.billZip", "Value=87653", ENDITEM, 
		"Name=order.billCountry", "Value=USA", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value=tl1dMsAUj3vOy6xD__Rb-2hwqFH9QxsN8ufes2WG7-upN8g-eJU98jpMG6N6w92RkWiktV_pFPTrC0U8vHOs6TvoIW93zZ0NokaJawgLbpg=", ENDITEM, 
		"Name=__fp", "Value=Io9ErupdROIwVx4hQu2zL5wsi9MwZT6EDT9iLmzq85RKJBWJ27s_dgwMFN1Goorr-STPzhb20dosfYdo_GINcqvQSr9fTE91-5trGBZZDLgErevmq44Rog==", ENDITEM, 
		LAST);

	lr_end_transaction("10_EnterPaymentDetailsAndContinue",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("11_ConfirmTheOrder");

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("11_ConfirmTheOrder",LR_AUTO);

	lr_start_transaction("12_SignOut");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("12_SignOut",LR_AUTO);

	return 0;
}