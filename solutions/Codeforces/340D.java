//Problem Name : 340D - Bubble Sort Graph
//Execution Time : 312 ms
//Memory : 100 KB
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
    <meta property="og:title" content="Submission #4084053 - Codeforces"/>
    <meta property="og:site_name" content="Codeforces"/>
    
    <meta name="cc" content="1p1d4x9c2zd93"/>
    
    <meta name="verify-reformal" content="f56f99fd7e087fb6ccb48ef2" />
    <title>Submission #4084053 - Codeforces</title>
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

    window.getCodeforcesServerTime = function(callback) {
        $.post("/data/time", {}, callback, "json");
    }

    window.updateTypography = function () {
        $("div.ttypography code").addClass("tt");
        $("div.ttypography pre>code").addClass("prettyprint").removeClass("tt");
        $("div.ttypography table").addClass("bordertable");
        prettyPrint();
    }

    $.ajaxSetup({ scriptCharset: "utf-8" ,contentType: "application/x-www-form-urlencoded; charset=UTF-8", headers: {
        'X-Csrf-Token': Codeforces.getCsrfToken()
    }});

    window.updateTypography();

    Codeforces.signForms();

    $(".second-level-menu-list").lavaLamp({
        fx: "backout",
        speed: 1000
    });


    Codeforces.countdown();
    $("a[rel='photobox']").colorbox();


        });
    </script>
<script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-743380-5']);
  _gaq.push(['_trackPageview']);

  (function () {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = (document.location.protocol == 'https:' ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script>
<div id="body">
        <!-- Frame: Header.ftl -->
<div id="header" style="position:relative;">
    <div style="float:left;">
            <a href="/"><img src="http://worker.codeforces.ru/static/images/codeforces-logo-with-upper-beta.png"/></a>
    </div>
    <div class="lang-chooser">
        <div style="text-align: right;">
            <a href="?locale=en"><img src="http://worker.codeforces.ru/static/images/flags/24/gb.png" title="In English" alt="In English"/></a>
            <a href="?locale=ru"><img src="http://worker.codeforces.ru/static/images/flags/24/ru.png" title="По-русски" alt="По-русски"/></a>
        </div>
        <div>
                <a href="/enter">Enter</a>
                 | 
                <a href="/register">Register</a>
                
        </div>
    </div>
    <div style="font-size:0.8em;margin-top:0.25em;position:absolute;right:0;top:4.25em;">
    </div>
    <br style="clear: both;"/>
</div>
<!-- /Frame: Header.ftl -->
        <!-- Frame: MainMenuFrame.ftl -->
    <div class="roundbox menu-box" style="">
            <div class="roundbox-lt"> </div>
            <div class="roundbox-rt"> </div>
            <div class="roundbox-lb"> </div>
            <div class="roundbox-rb"> </div>
<div class="menu-list-container">
    <ul class="menu-list main-menu-list">
                <li class=""><a href="/">Home</a></li>
                <li class="current"><a href="/contests">Contests</a></li>
                <li class=""><a href="/gyms">Gym</a></li>
                <li class=""><a href="/problemset">Problemset</a></li>
                <li class=""><a href="/groups">Groups</a></li>
                <li class=""><a href="/ratings">Rating</a></li>
                <li class=""><a href="/api/help">API</a></li>
                <li class=""><a href="/help">Help</a></li>
                <li class=""><a href="/rcc2014">RCC <img class="icon" src="http://stat.codeforces.ru/images/icons/cup.png"/></a></li>
                <li class=""><a href="/memsql2014">MemSQL Start[c]UP 2.0 <img class="icon" src="http://stat.codeforces.ru/images/icons/cup.png"/></a></li>
    </ul>
    <form method="post" action="/search"><input type='hidden' name='csrf_token' value='7e8h7eb15h00273b5eb2fb58d8717h7a'/>
        <input class="search" name="query" data-isPlaceholder="true" value="Search by tag"/>
    </form>
    <br style="clear: both;"/>
</div>
    </div>
<!-- /Frame: MainMenuFrame.ftl -->
    <script type="text/javascript">
        $(document).ready(function() {
            $("input.search").focus(function() {
                if ($(this).attr("data-isPlaceholder") === "true") {
                    $(this).val("");
                    $(this).removeAttr("data-isPlaceholder");
                }
            });
        });
    </script>
        <br style="height: 3em; clear: both;"/>
        <div style="position: relative;">
                <div id="content">
                <div class="second-level-menu"><!-- Frame: SecondLevelMenuFrame.ftl -->
<ul class="second-level-menu-list">
        <li><a
                                        href="/contest/297">Problems</a></li>
        <li><a
                                        href="/contest/297/submit">Submit Code</a></li>
        <li><a
                                        href="/contest/297/my">My Submissions</a></li>
        <li class="current"><a
                                        href="/contest/297/status">Status</a></li>
        <li><a
                                        href="/contest/297/hacks">Hacks</a></li>
        <li><a
                                        href="/contest/297/room/1">Room</a></li>
        <li><a
                                        href="/contest/297/standings">Standings</a></li>
        <li><a
                                        href="/contest/297/customtest">Custom Invocation</a></li>
</ul>
<!-- /Frame: SecondLevelMenuFrame.ftl --></div>
<!-- Frame: SubmissionDetailsFrame.ftl -->

<div class="datatable"
     
     style="background-color: #E1E1E1;padding-bottom:3px;">
            <div class="lt"> </div>
            <div class="rt"> </div>
            <div class="lb"> </div>
            <div class="rb"> </div>

            <div style="padding: 4px 0 0 6px;font-size:1em;position:relative;">
                General

                <div style="position:absolute;right:0.25em;top:0.35em;">
                    <img class="closed" src="http://worker.codeforces.ru/static/images/icons/control.png"/>

                    <span class="filter" style="display:none;">
                        <img class="opened" src="http://worker.codeforces.ru/static/images/icons/control-270.png"/>
                        <input style="position:relative;bottom:2px;border:1px solid #aaa;height:17px;font-size:13px;"/>
                    </span>
                </div>
            </div>
            <div style="background-color: white;margin:0.3em 3px 0 3px;position:relative;">
            <div class="ilt"> </div>
            <div class="irt"> </div>
            <table class="">
<tr>
    <th style="width:2em;">#</th>
    <th style="width:12em;">Author</th>
    <th style="width:2em;">Problem</th>
    <th style="width:2em;">Lang</th>
    <th style="width:8em;">Verdict</th>
    <th style="width:2em;">Time</th>
    <th style="width:2em;">Memory</th>
    <th style="width:4em;">Sent</th>
    <th style="width:4em;">Judged</th>
</tr>
<tr>
    <td>4084053</td>
    <td>
            Practice:<br/>
<a href="/profile/ffao" title="Grandmaster ffao" class="rated-user user-red">ffao</a>    </td>
    <td>
        <a title="C - Splitting the Uniqueness" href="/contest/297/problem/C">297C</a>
         - <span title="problem revision">24</span>
    </td>
    <td>
    Java 7
    </td>
    <td>
    <span class='verdict-accepted'>Accepted</span>
    </td>
    <td>
        359 ms
    </td>
    <td>
        168 KB
    </td>
    <td>2013-07-17 09:26:23</td>
    <td>2013-07-17 09:26:23</td>
</tr>
            </table>
            </div>
        </div>
    <script type="text/javascript">
        $(document).ready(function() {
                // Create new ':containsIgnoreCase' selector for search
                jQuery.expr[':'].containsIgnoreCase = function(a, i, m) {
                    return jQuery(a).text().toUpperCase()
                            .indexOf(m[3].toUpperCase()) >= 0;
                };

                if (window.updateDatatableFilter == undefined) {
                    window.updateDatatableFilter = function(i) {
                        var parent = $(i).parent().parent().parent().parent();
                        $("tr.no-items", parent).remove();
                        $("tr", parent).hide().removeClass><pre>21
22 18 0 13 7 8 23 21 24 6 25 17 14 10 2 11 5 15 16 20 12
