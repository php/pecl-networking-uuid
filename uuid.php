<?php
if(!extension_loaded('uuid')) {
	dl('uuid.so');
}
$module = 'uuid';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:<br>\n";
foreach($functions as $func) {
    echo $func."<br>\n";
}
echo "<br>\n";
if (extension_loaded($module)) {
	$str = sprintf("Module %s version %s loaded", $module, phpversion($module));
} else {
	$str = "Module $module is not compiled into PHP";
}
echo "$str\n";
?>
