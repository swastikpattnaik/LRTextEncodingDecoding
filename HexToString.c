HexToString()
{
	lr_save_string("tjIAKJprJ\\x2FxoK2GJL\\x2BZMhgUm9Wat4j16dw\\x2B7o4d9Lak\\x3D", "hex_data");

	lr_output_message(lr_eval_string("{hex_data}"));

	convert_hexparam("hex_data");
	
	lr_output_message(lr_eval_string("{hex_data}"));
	
	return 0;
}
