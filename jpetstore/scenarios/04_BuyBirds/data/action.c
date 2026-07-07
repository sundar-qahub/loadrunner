Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("petstore.octoperf.com", 
		"URL=https://petstore.octoperf.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(16);

	lr_start_transaction("1_Launch");

	web_url("petstore.octoperf.com_2", 
		"URL=https://petstore.octoperf.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_Launch",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("2_ClickEnterTheStore");

	web_url("Catalog.action", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("2_ClickEnterTheStore",LR_AUTO);

	lr_think_time(9);

	lr_start_transaction("3_ClickSignIn");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=AC0B44DB59C8A6F432F73060EF63454A?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_ClickSignIn",LR_AUTO);

	lr_start_transaction("4_ClickLogin");

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=AC0B44DB59C8A6F432F73060EF63454A?signonForm=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=username", "Value=perfuser01", ENDITEM, 
		"Name=password", "Value=perfuser@01", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=fGI9Y6Fz3rDvL8AyTTtD62kquJImx32uFVPYX7_PXYX57wEv2T0d7uaFCd2hbohSfkzhDS6UlXL13Jkwa0nJvC0yNxksWK0d_mrLD4GFrnw=", ENDITEM, 
		"Name=__fp", "Value=Aad_ECw8vu7kU-fcr01QEekPnipcCKpcVPjdAOanhIn9iy0eC0s_Jk7dSTs_IzgE", ENDITEM, 
		LAST);

	lr_end_transaction("4_ClickLogin",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("5_ClickPetFish");

	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("5_ClickPetFish",LR_AUTO);

	lr_think_time(30);

	lr_start_transaction("6_SelectPetProduct");

	web_url("FI-SW-01", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("6_SelectPetProduct",LR_AUTO);

	lr_think_time(44);

	lr_start_transaction("7_AddToCartPetitem");

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-01", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("7_AddToCartPetitem",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("8_updateRandomQuantityAndUpdateCart");

	web_submit_data("Cart.action", 
		"Action=https://petstore.octoperf.com/actions/Cart.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-1", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=EST-1", "Value=3", ENDITEM, 
		"Name=updateCartQuantities", "Value=Update Cart", ENDITEM, 
		"Name=_sourcePage", "Value=NAycRyHpPtMM20YscZJyCF-pNFxZhDeGt1ug7WAsncmM58hn6j-Lm9h9B1oiyukXa-neRYfcqbq_e2lPBcjJPN8Xb1KJpgiO", ENDITEM, 
		"Name=__fp", "Value=VJsfAbCcQxMTxDAyl4oXChMx0DX_Yz57MDO1CMOvD3Q7qHgqBtSc20sYTa0ZAEeF", ENDITEM, 
		LAST);

	lr_end_transaction("8_updateRandomQuantityAndUpdateCart",LR_AUTO);

	lr_think_time(29);

	lr_start_transaction("9_ClickProceedToCheckOut");

	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("9_ClickProceedToCheckOut",LR_AUTO);

	lr_think_time(38);

	lr_start_transaction("10_EnterPaymentAndContinue");

	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t12.inf", 
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
		"Name=_sourcePage", "Value=sf-oM3CPu4eCXqgrCvQi49e7bPoC49aa87lVM6Uh9XzzaQZsXTjPdxbBjarUpTj8jRcT5l0VN-aEFrLzJToCm8Xv_XQbQ91S31yr6vjsCug=", ENDITEM, 
		"Name=__fp", "Value=GP-qJowMPw7mcAo9tjRqIJ28jgDoDGzyuPJCX9hVcTI6pkPYtuyg0tLNrS77KEmQ6BloxprYVctGvW3672OWH7epQCxWH4qeCbmsPmwbUr8aASzon7B6Bg==", ENDITEM, 
		LAST);

	lr_end_transaction("10_EnterPaymentAndContinue",LR_AUTO);

	lr_think_time(30);

	lr_start_transaction("11_ConfirmOrder");

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("11_ConfirmOrder",LR_AUTO);

	lr_start_transaction("12_ClickSignout");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("12_ClickSignout",LR_AUTO);

	return 0;
}