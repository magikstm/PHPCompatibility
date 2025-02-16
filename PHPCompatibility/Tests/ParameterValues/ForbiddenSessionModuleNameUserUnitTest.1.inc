<?php
/*
 * Test session_module_name() PHP 7.2 change in accepted values.
 */

// OK.
session_module_name(module: $module);
session_module_name();
session_module_name('user' . $something);
session_module_name(<<<EOD
user-nonsense
EOD
);

// Not OK.
session_module_name('user',);
session_module_name(module: "USER");
session_module_name(<<<'EOD'
user
EOD
);

// Safeguard against false positives on method calls.
ClassName::session_module_name('user');
$obj->session_module_name('user');
$obj?->session_module_name('user'); // PHP 8.0+.

// Safeguard no false positives on PHP 8.1+ first class callables.
register_callback(session_module_name(...));

// Safeguard against false positives when target param not found.
session_module_name(name: 'user'); // Wrong param name.
