URLTextConversion()
{
	//URL to Plain Text Conversion	
	lr_save_string("%3Cmytag%3E%26", "pString");
	
	lr_output_message("Before Conversion in URL: %s", lr_eval_string("{pString}"));
	
	web_convert_param("pString", "SourceEncoding=URL", "TargetEncoding=PLAIN", LAST);	

	lr_output_message("After Conversion in Plain Text: %s", lr_eval_string("{pString}"));
	
	//Plain Text to URL Conversion	
	lr_save_string("<Loadtester>&", "pSecondString");
	
	lr_output_message("Before Conversion in Plain Text: %s", lr_eval_string("{pSecondString}"));
	
	web_convert_param("pSecondString", "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST);	

	lr_output_message("After Conversion in URL: %s", lr_eval_string("{pSecondString}"));
	
	return 0;
}
