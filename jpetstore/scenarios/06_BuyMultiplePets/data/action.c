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

	lr_think_time(4);

	lr_start_transaction("3_ClickSignIn");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=7129056B2BA9C210E8233D6585F2F7E5?signonForm=", 
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
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=7129056B2BA9C210E8233D6585F2F7E5?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=username", "Value=perfuser01", ENDITEM, 
		"Name=password", "Value=perfuser@01", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=mTLXV-awfPzYwmA1XDyEaGbSceKO8AGhAmfXzC1haTV8r4asgEBeseyUKWu1bJoqi_WsqTqMRd8SRXQRKKm3OYAy2p14EJOets4n13qDqlc=", ENDITEM, 
		"Name=__fp", "Value=9TeuIvWcOXK0bTaD99sPBL5QUewckMUEHd_pxnJXO0JXHgs-G_LLgtNCYXaRmWHD", ENDITEM, 
		LAST);

	lr_end_transaction("4_ClickLogin",LR_AUTO);

	lr_think_time(28);

	lr_start_transaction("5_ClickPet1");

	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("5_ClickPet1",LR_AUTO);

	lr_think_time(36);

	lr_start_transaction("6_SelectPet1Product");

	web_url("FI-SW-02", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-02", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("6_SelectPet1Product",LR_AUTO);

	lr_think_time(59);

	lr_start_transaction("7_ClickAddToCartPet1Item");

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-3", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-02", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("7_ClickAddToCartPet1Item",LR_AUTO);

	lr_think_time(42);

	lr_start_transaction("8_UpdateRandomQuantityAndUpdateCart");

	web_submit_data("Cart.action", 
		"Action=https://petstore.octoperf.com/actions/Cart.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-3", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=EST-3", "Value=3", ENDITEM, 
		"Name=updateCartQuantities", "Value=Update Cart", ENDITEM, 
		"Name=_sourcePage", "Value=mQPk_qmdBZLnOzAwPr-5RxUI5xQsqo5RsJt4wM_nXuJ9QDQHry_tkWtKAanIJSYTFTYBNTwx5nIOLV0siVthKVh50LGY2s8O", ENDITEM, 
		"Name=__fp", "Value=ThiuyHkYfUrPAPeVizwrkMqkpfWF0f9xZii-9u_kj8utjGcRiH9OXDtEKchIgQGa", ENDITEM, 
		LAST);

	lr_end_transaction("8_UpdateRandomQuantityAndUpdateCart",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("9_ReturnToMainMenu");

	web_url("Return to Main Menu", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("9_ReturnToMainMenu",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("10_SelectPet2");

	web_url("sm_dogs.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=DOGS", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("10_SelectPet2",LR_AUTO);

	lr_think_time(29);

	lr_start_transaction("11_SelectPet2Product");

	web_url("K9-DL-01", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=K9-DL-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=DOGS", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("11_SelectPet2Product",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("12_AddToCartPet2Item");

	web_url("Add to Cart_2", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-10", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=K9-DL-01", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("12_AddToCartPet2Item",LR_AUTO);

	lr_think_time(40);

	lr_start_transaction("13_UpdateRandomQuanityPet2ItemAndUpdateCart");

	web_submit_data("Cart.action_2", 
		"Action=https://petstore.octoperf.com/actions/Cart.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-10", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=EST-3", "Value=3", ENDITEM, 
		"Name=EST-10", "Value=4", ENDITEM, 
		"Name=updateCartQuantities", "Value=Update Cart", ENDITEM, 
		"Name=_sourcePage", "Value=XlchmleA_zImKn7GNMkqyCGNZPt-EtR3WjW3EM3PxYWc7LQN83GtKEcc5ayFej9HiMFfKw5ncndCupuiQvY-tuZZdS9En3Th", ENDITEM, 
		"Name=__fp", "Value=rqSIXgQy2SQFS5a7kJMc3VPNpK6tggar46KjkAydJZAN6eIdZg57hNdXi29CLrOi", ENDITEM, 
		LAST);

	lr_end_transaction("13_UpdateRandomQuanityPet2ItemAndUpdateCart",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("15_ProceedToCheckOut");

	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("15_ProceedToCheckOut",LR_AUTO);

	lr_think_time(34);

	lr_start_transaction("16_EnterPaymentDetailsAndContinue");

	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t14.inf", 
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
		"Name=_sourcePage", "Value=LanDoU0cUWa_jIitusWzGqp5tQBwxuKlbQJxfwjumRhmHV2PpezTGPsABzPz1fZ-R1p16gpCVuanMJca2bBvj-Ph4nV6oR8LmbQuAqDv3LQ=", ENDITEM, 
		"Name=__fp", "Value=B-gWkbcCazi74KUDZVMJwBIt5aeblflQB-hHwyUQ9jKUWVGWU4XRRGLwgsyHGlBnrrFxNKhW0GHJA4O7NZ-3fF58atdKY826dDe-n68_kGU97YkGVcJHrA==", ENDITEM, 
		LAST);

	lr_end_transaction("16_EnterPaymentDetailsAndContinue",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("17_ConfirmTheOrder");

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("17_ConfirmTheOrder",LR_AUTO);

	lr_start_transaction("18_SignOut");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("18_SignOut",LR_AUTO);

	return 0;
}