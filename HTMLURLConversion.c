HTMLURLConversion()
{
	//HTML to URL Conversion		
	lr_save_string("&lt;Loadtester&gt;&amp;", "pScottString");
	
	lr_output_message("Before Conversion in HTML: %s", lr_eval_string("{pScottString}"));
	
	web_convert_param("pScottString", "SourceEncoding=HTML", "TargetEncoding=URL", LAST);

	lr_output_message("After Conversion in URL: %s", lr_eval_string("{pScottString}"));
	
	//URL to HTML Conversion	
	lr_save_string("%3Cmytag%3E%26", "pString");
	
	lr_output_message("Before Conversion in URL: %s", lr_eval_string("{pString}"));
	
	web_convert_param("pString", "SourceEncoding=URL", "TargetEncoding=HTML", LAST);	

	lr_output_message("After Conversion in HTML: %s", lr_eval_string("{pString}"));
	
	return 0;
}
