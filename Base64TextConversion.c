Base64TextConversion()
{
	sourceMessage="demande.demandeur:123456789";

	//Loading the Library micsocket.dll
	lr_load_dll("micsocket.dll");
	
	//Base64 Encoding
	encodedMessage= util_base64encode(sourceMessage);

	lr_message("Source message is:\n %s ",sourceMessage);
	lr_message("Encoded message is:\n %s ",encodedMessage);

	//Base64 Decoding
	decodedMessage=util_base64decode(encodedMessage);

	lr_message("%s ",decodedMessage);
//	lr_output_message("Decoded String is %s", decodedMessage);	
	
	lr_save_string(decodedMessage, "pDecodedString");
	lr_output_message("Decoded String is %s", lr_eval_string("{pDecodedString}"));	
	
	return 0;
}
