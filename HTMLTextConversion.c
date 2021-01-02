HTMLTextConversion()
{
	//HTML to Plain Text Conversion		
	lr_save_string("&lt;Loadtester&gt;&amp;", "pScottString");
	
	lr_output_message("Before Conversion in HTML: %s", lr_eval_string("{pScottString}"));
	
	web_convert_param("pScottString", "SourceEncoding=HTML", "TargetEncoding=PLAIN", LAST);

	lr_output_message("After Conversion in Plain Text: %s", lr_eval_string("{pScottString}"));
	
	//Plain Text to HTML Conversion	
	lr_save_string("<mytag>&", "pString");
	
	lr_output_message("Before Conversion in Plain Text: %s", lr_eval_string("{pString}"));
	
	web_convert_param("pString", "SourceEncoding=PLAIN", "TargetEncoding=HTML", LAST);	

	lr_output_message("After Conversion in HTML: %s", lr_eval_string("{pString}"));
	
	return 0;
}
