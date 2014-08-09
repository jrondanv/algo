//Problem Name : 455B - A Lot of Games
//Execution Time : 31 ms
//Memory : 116400 KB
PE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html>
<head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <meta name="X-Csrf-Token" content="7e8h7eb15h00273b5eb2fb58d8717h7a"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <meta http-equiv="pragma" content="no-cache">
    <meta http-equiv="expires" content="-1">
    <meta http-equiv="profileName" content="p1">
    <meta name="google-site-verification" content="OTd2dN5x4nS4OPknPI9JFg36fKxjqY0i1PSfFPv_J90"/>
    <meta property="fb:admins" content="100001352546622" />
    <meta property="og:image" content="http://worker.codeforces.ru/static/images/codeforces-vk-square-en.png"/>
    <meta property="og:title" content="Submission #4789850 - Codeforces"/>
    <meta property="og:site_name" content="Codeforces"/>
    
    <meta name="cc" content="56q2ntek0kcj"/>
    
    <meta name="verify-reformal" content="f56f99fd7e087fb6ccb48ef2" />
    <title>Submission #4789850 - Codeforces</title>
        <meta name="description" content="Codeforces. Programming competitions and contests, programming community" />
        <meta name="keywords" content="programming algorithm contest competition informatics olympiads c++ java graphs vkcup" />
    <meta name="robots" content="index, follow" />

    <link rel="stylesheet" href="http://worker.codeforces.ru/static/css/font-awesome.min.css" type="text/css" charset="utf-8" />

        <link href='//fonts.googleapis.com/css?family=Cuprum&subset=latin,cyrillic' rel='stylesheet' type='text/css'>


    <link rel="shortcut icon" type="image/png" href="http://worker.codeforces.ru/static/favicon.png">

    <!--CombineResourcesFilter-->
    <LINK charset="utf-8" href="http://worker.codeforces.ru/static/combine/cfb02261756f2ccef9c62a137d80f16f_71dd0e3c34799558144ea89f7a6e54cf.css" rel="stylesheet" type="text/css"/>
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
        

    <SCRIPT src="http://worker.codeforces.ru/static/combine/89b3ee750b2212159cecc5edcdb53b8e_fea11fc7deebf9a46491423e00bd8b9.js" type="text/javascript"> </SCRIPT>
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    <!--/CombineResourcesFilter-->

    <link rel="stylesheet" href="http://worker.codeforces.ru/static/markitup/skins/markitup/style.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="http://worker.codeforces.ru/static/markitup/sets/markdown/style.css" type="text/css" charset="utf-8" />

    <script type="text/javascript" src="//yandex.st/share/share.js" charset="utf-8"></script>
    
    <script type="text/javascript" src="http://worker.codeforces.ru/static/markitup/jquery.markitup.js"></script>
    <script type="text/javascript" src="http://worker.codeforces.ru/static/markitup/sets/markdown/set.js"></script>

    <!--[if IE]>
    <style>
        #sidebar {
            padding-left: 1em;
            margin: 1em 1em 1em 0;
        }
    </style>
    <![endif]-->


</head>
<body><span style='display:none;' class='csrf-token' data-csrf='7e8h7eb15h00273b5eb2fb58d8717h7a'> </span>
<!-- Codeforces JavaScripts. -->
<script type="text/javascript">
    if (window.parent.frames.length > 0) {
        window.stop();
    }
</script>

    <script type="text/javascript">
        $(document).ready(function() {
    $.ajaxPrefilter(function(options, originalOptions, xhr) {
        var csrf = Codeforces.getCsrfToken();

        if (csrf) {
            var data = originalOptions.data;
            if (originalOptions.data !== undefined) {
                if (Object.prototype.toString.call(originalOptions.data) === '[object String]') {
                    data = $.deparam(originalOptions.data);
                }
            } else {
                data = {};
            }
            options.data = $.param($.extend(data, { csrf_token: csrf }));
        }
    });

    window.getCodeforcesServerTime = funct