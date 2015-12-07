define(['Mustache'],function(Mustache){   
    var t = $('#tpl').html();
    Mustache.parse(t);  

    var tplBdImgs = $('#tpl_bdimgs').html();    
    Mustache.parse(tplBdImgs);  

    var render_plant_list = function(start_id){
        var render = function(data){
            var html = Mustache.render(t, data); 
            $("#plants").html(Mustache.render(t, data));  
            render_plant(data.data[0].pk_id); 
            $("#plants li:first-child").attr('class','active');
        };

        if(isRelease){
            $.getJSON('/api/plant/list',function(data){
                render(data);
            }); 
        }else{            
            var data = {"data":[{"pk_id":"1","name_cn":"\u6cb9\u68d5"},{"pk_id":"2","name_cn":"\u5927\u4e1d\u8475"},{"pk_id":"3","name_cn":"\u4e91\u5357\u7701\u85e4"},{"pk_id":"4","name_cn":"\u4e8c\u5217\u7701\u85e4"},{"pk_id":"5","name_cn":"\u5c0f\u767d\u85e4"},{"pk_id":"6","name_cn":"\u67f3\u6761\u7701\u85e4"},{"pk_id":"7","name_cn":"\u6bdb\u9cde\u7701\u85e4"},{"pk_id":"8","name_cn":"\u76f4\u7acb\u7701\u85e4"},{"pk_id":"9","name_cn":"\u5927\u767d\u85e4"},{"pk_id":"10","name_cn":"\u957f\u97ad\u85e4"},{"pk_id":"11","name_cn":"\u7f05\u7538\u7701\u85e4"},{"pk_id":"12","name_cn":"\u6756\u85e4"},{"pk_id":"13","name_cn":"\u85cf\u6ce2\u7f57\u82b1"},{"pk_id":"14","name_cn":"\u5927\u53f6\u767e\u4e24\u91d1"},{"pk_id":"15","name_cn":"\u5c71\u8840\u4e39"},{"pk_id":"16","name_cn":"\u7ec6\u7f57\u4f1e"},{"pk_id":"17","name_cn":"\u7ec6\u67c4\u767e\u4e24\u91d1"},{"pk_id":"18","name_cn":"\u6bdb\u53f6\u96ea\u4e0b\u7ea2"},{"pk_id":"19","name_cn":"\u72ed\u53f6\u96ea\u4e0b\u7ea2"},{"pk_id":"20","name_cn":"\u77ed\u67c4\u6708\u6708\u7ea2"},{"pk_id":"21","name_cn":"\u8c79\u5b50\u773c\u775b\u679c"},{"pk_id":"22","name_cn":"\u725b\u820c\u8349"},{"pk_id":"23","name_cn":"\u5149\u53f6\u7c97\u7ce0\u6811"},{"pk_id":"24","name_cn":"\u8fa3\u6c41\u6811"},{"pk_id":"25","name_cn":"\u7f51\u8109\u6842"},{"pk_id":"26","name_cn":"\u94f6\u6728"},{"pk_id":"27","name_cn":"\u67f4\u6842"},{"pk_id":"28","name_cn":"\u5ddd\u6842"},{"pk_id":"29","name_cn":"\u5e7f\u897f\u9493\u6a1f"},{"pk_id":"30","name_cn":"\u7ea4\u6897\u5c71\u80e1\u6912"},{"pk_id":"31","name_cn":"\u6ce2\u5bc6\u9493\u6a1f"},{"pk_id":"32","name_cn":"\u65e0\u6bdb\u5c71\u80e1\u6912"},{"pk_id":"33","name_cn":"\u6da6\u6960"},{"pk_id":"34","name_cn":"\u7d2b\u53f6\u743c\u6960"},{"pk_id":"35","name_cn":"\u6bd5\u6f84\u8304"},{"pk_id":"36","name_cn":"\u5355\u53f6\u5434\u8438"},{"pk_id":"37","name_cn":"\u4e09\u6860\u82e6"},{"pk_id":"38","name_cn":"\u725b\u7d0f\u5434\u8438"},{"pk_id":"39","name_cn":"\u693f\u53f6\u82b1\u6912"},{"pk_id":"40","name_cn":"\u5f02\u53f6\u82b1\u6912"},{"pk_id":"41","name_cn":"\u82b1\u6912"},{"pk_id":"42","name_cn":"\u5cad\u5357\u82b1\u6912"},{"pk_id":"43","name_cn":"\u7af9\u53f6\u82b1\u6912"},{"pk_id":"44","name_cn":"\u5927\u53f6\u81ed\u82b1\u6912"},{"pk_id":"45","name_cn":"\u781a\u58f3\u82b1\u6912"},{"pk_id":"46","name_cn":"\u82b1\u83d6\u84b2"},{"pk_id":"47","name_cn":"\u641c\u5c71\u9ec4"},{"pk_id":"48","name_cn":"\u5355\u5305\u9e22\u5c3e"},{"pk_id":"49","name_cn":"\u674e\u53f6\u6986"},{"pk_id":"50","name_cn":"\u6bdb\u679d\u6986"}]};
            render(data); 

        } 
        
    };

    var render_plant = function(pk_id){ 
        var render = function(data){
            $('body').scrollTop(0);
            $("#cb_saw").prop("checked",false);
            $("#lifesort input[value=unknown]").prop("checked",true);
            $("#leavestem input[value=unknown]").prop("checked",true);

            $("#hName").html(data.name_cn+"(" + data.name_lati + ")");

            $("#name_lati").val(data.name_lati);
            $("#name_alias").val(data.name_alias);
            $("#species").val(data.species);
            $("#series").val(data.series);
            $("#genus").text(data.genus);
            $("#tribe").val(data.tribe);
            $("#family").text(data.family);
            $("#order").text(data.order);
            $("#class").text(data.class);
            $("#phylum").text(data.phylum);
            // $("#bd_baike").html(bd_baike);

            var html = Mustache.render(tplBdImgs, data); 
            $("#bd_imgs").html(Mustache.render(tplBdImgs, data)); 

            

            $("#plants li").attr('class','');
            $("#li_p_"+pk_id).attr('class','active');

            location.hash = pk_id;

        }; 

        if(isRelease){
            $.getJSON('/api/plant',{'id':pk_id},function(data){
                render(data);

                
            });

        }else{

            var data = 
            {"pk_id":"1","name_cn":"\u6cb9\u68d5","name_lati":"ElaeisguineensisJacq.","name_alias":null,"species":null,"series":null,"section":null,"genus":"\u6cb9\u68d5\u5c5e","tribe":"\u6930\u5b50\u65cf","family":"\u68d5\u6988\u79d1","order":"\u521d\u751f\u76ee","class":"\u5355\u5b50\u53f6\u690d\u7269\u7eb2","phylum":"\u88ab\u5b50\u690d\u7269\u95e8","tags":null,"create_date":null,"last_update":"2015-11-07 11:54:18","bd_imgs":["http:\/\/baike.ys005.com\/uploads\/201004\/1270445362IgVXwqDq.jpg","http:\/\/www.user1.jqw.com\/2011\/01\/11\/324602\/product\/b201101121825527697.jpg","http:\/\/pic.baike.soso.com\/p\/20100920\/bki-20100920153034-1649501502.jpg","http:\/\/www.civilcn.com\/photo\/248.jpg","http:\/\/www.zhiwuwang.com\/baike\/uploads\/201304\/1366098569t1fBMum4.png","http:\/\/wiki.zhulong.com\/upload\/2007\/05\/16\/2006041214282439_1m.jpg","http:\/\/www.best-jx.com\/Public\/uploadfiles\/upload\/day_111130\/201111301110255138.jpg","http:\/\/www.xtbg.ac.cn\/xwzx\/ylxx\/201211\/W020121112604199417674.jpg","http:\/\/www.user1.jqw.com\/2011\/01\/11\/324602\/product\/b201101121826270566.jpg","http:\/\/static.zhulong.com\/photo\/small\/200604\/12\/28450_2_0_0_560_w_0.jpg","http:\/\/g.hiphotos.baidu.com\/baike\/pic\/item\/ca1349540923dd54d08b8ebcd109b3de9d82486d.jpg","http:\/\/s1.sinaimg.cn\/middle\/a5bce8acgc31abafd7dc0&690","http:\/\/s8.sinaimg.cn\/middle\/a5bce8acgc876fb189c77&690","http:\/\/img6.ph.126.net\/xRx5IqE_oFoGRJYYU9kmYA==\/2804616667962226456.jpg","http:\/\/www.zhiwuwang.com\/baike\/uploads\/201304\/1366098621FNlWO8MX.png","http:\/\/www.yuanlin.com\/B2B\/UpFile_Image\/Biz\/2011-1\/20118301239257860.jpg","http:\/\/s9.sinaimg.cn\/middle\/7fba5bcega4d64be8d188&690","http:\/\/i1.sinaimg.cn\/dy\/w\/2011-11-18\/1321587961_wA9B1E.jpg","http:\/\/static.zhulong.com\/photo\/small\/200604\/12\/28449_1_0_0_560_w_0.jpg","http:\/\/a2.att.hudong.com\/45\/33\/01300000255359122423330832886.jpg","http:\/\/img1.3lian.com\/img2011\/17\/78\/02.jpg","http:\/\/www.yuanlin.com\/B2B\/UPFile_Image\/Biz\/2009-3\/20093161630523626.jpg","http:\/\/pic.biodiscover.com\/files\/u\/8t\/biodiscover_5203757.jpg","http:\/\/www.chichayou.com\/uploads\/2013-11\/1-13112P9341K47.jpg","http:\/\/www.gzweisipiju.com\/img\/aHR0cDovL3RyYXZlbC5tb25nYWJheS5jb20vbWFsYXlzaWEvNjAwL2Jvcm5lb180NTIzLkpQRw==.jpg","http:\/\/bbsfile.co188.com\/forum\/month_1107\/20110703_759ea69129dd34d16a12bjPefzyfctAe.jpg","http:\/\/img.caijing.com.cn\/2008-11-17\/110028971.JPG","http:\/\/file.youboy.com\/a\/96\/63\/87\/8\/10246058.jpg","http:\/\/s9.sinaimg.cn\/orignal\/487a3140467c64ebe8ab8","http:\/\/www.flowerworld.com.cn\/preViewImg\/b5d69f60314dbb1ae5b065a55c197160.jpg","http:\/\/s11.sinaimg.cn\/middle\/4b1cdc23x7eb0368b5daa&690","http:\/\/pic17.huitu.com\/res\/20140303\/426321_20140303004034404171_1.jpg","http:\/\/hr.hrtv.cn\/uploads\/allimg\/130729\/10-130H9112616356.jpg","http:\/\/www.xtbg.ac.cn\/xwzx\/ylxx\/201211\/W020121112604199430839.jpg","http:\/\/www.ylstudy.com\/data\/attachment\/forum\/forumid_9\/0904081105b0a64b22bd55c12d.jpg","http:\/\/pic.baike.soso.com\/p\/20100920\/20100920153139-1465101567.jpg","http:\/\/www.yuhuagu.com\/uploads\/allimg\/130607\/10-13060H11128.jpg","http:\/\/img.ph.126.net\/3Q7C_-C_AXTuiaK9pjmqzw==\/3319715875326271894.jpg","http:\/\/www.cgrealm.org\/u\/img\/model\/2010-08-22_213306.jpg","http:\/\/zjphoto.yinsha.com\/file\/200510\/2005102409324380\/1.jpg","http:\/\/s3.sinaimg.cn\/middle\/a5bce8acgc876fb2ede12&690","http:\/\/files1.szhome.com\/UploadFiles\/BBS\/2004\/02\/12\/2731058_58269.33.jpg","http:\/\/p4.img.cctvpic.com\/nettv\/nongye\/20120724\/images\/114248_1343115192966.JPG","http:\/\/rri.catas.cn\/ufiles\/Image\/2012-12\/image002%280001%29.jpg","http:\/\/b2b.image.yuanlin.com\/biz\/2009-3\/2009316162831923.jpg","http:\/\/img0.ph.126.net\/bPDdhe2dbrAr-nk39cVJ0g==\/6597570044448711297.jpg","http:\/\/s14.sinaimg.cn\/bmiddle\/4cfcdf5406ea903f8542d","http:\/\/www.xtbg.ac.cn\/xwzx\/ylxx\/201211\/W020121112604199440367.jpg","http:\/\/file1.jydoc.com\/%D4%AA%CA%FD%BE%DD\/0712-02\/10548-%D3%CD%D7%D8.jpg","http:\/\/pic9.nipic.com\/20100827\/5615922_115831008323_2.jpg","http:\/\/img.pconline.com.cn\/images\/upload\/upc\/tx\/itbbs\/1001\/10\/c2\/2678877_1263126094690.jpg","http:\/\/static10.photo.sina.com.cn\/orignal\/4c22832965b09a2620a29","http:\/\/www.user1.jqw.com\/2012\/05\/31\/488629\/product\/b201206061346244515.jpg","http:\/\/static11.photo.sina.com.cn\/orignal\/4b751c1900ecb6f550cea","http:\/\/f.hiphotos.baidu.com\/zhidao\/pic\/item\/8694a4c27d1ed21b2374bdcaad6eddc451da3f5b.jpg","http:\/\/i1.sinaimg.cn\/dy\/green\/p\/2011-06-03\/U5170P1T1D22583495F23DT20110603152121.jpg","http:\/\/cc1.cache.cdqss.com\/photochengdu\/attachment\/forum\/201208\/05\/15292893vvgzw8biwzwut3.jpg","http:\/\/zjphoto.yinsha.com\/file\/200806\/2008061814494632\/1.jpg","http:\/\/f.hiphotos.baidu.com\/zhidao\/pic\/item\/6f061d950a7b02086e5e06db63d9f2d3572cc870.jpg","http:\/\/img3.douban.com\/view\/group_topic\/large\/public\/31527000-17.jpg",""],"bd_baike":"\"\u4e2d\u6587\u5b66\u540d\":\"\u6cb9\u68d5\",\"\u62c9\u4e01\u5b66\u540d\":\"ElaeisguineensisJacq.\",\"\u4e8c\u540d\u6cd5\":\"Elaeisguineensis\",\"\u754c\":\"\u690d\u7269\u754c\",\"\u95e8\":\"\u88ab\u5b50\u690d\u7269\u95e8\",\"\u7eb2\":\"\u5355\u5b50\u53f6\u690d\u7269\u7eb2\",\"\u76ee\":\"\u521d\u751f\u76ee\",\"\u79d1\":\"\u68d5\u6988\u79d1\",\"\u65cf\":\"\u6930\u5b50\u65cf\",\"\u5c5e\":\"\u6cb9\u68d5\u5c5e\",\"\u5206\u5e03\u533a\u57df\":\"\u539f\u4ea7\u975e\u6d32\u70ed\u5e26\u5730\u533a\uff0c\u4e2d\u56fd\u53f0\u6e7e\u3001\u6d77\u5357\u53ca\u4e91\u5357\u70ed\u5e26\u5730\u533a\u6709\u683d\u57f9\u3002\""}
            ; 
            render(data); 


        }


    }; 

    var move_next_plant = function(){
        //move to next        
        var nextli = $("#plants li").first();
        var next_plant_id = nextli.children().attr("href").replace("#","");
        location.hash = next_plant_id;
        render_plant(next_plant_id); 
    };

    var save = function(){
        var plant_id = location.hash.replace("#","");
        // console.log(plant_id);

        var saw =  $("#cb_saw").prop('checked');
        var lifesort = $("#lifesort input[type=radio]:checked").val();
        var leavestem = $("#leavestem input[type=radio]:checked").val();

        var imgs = [];
        $("#bd_imgs input[name=img_selected]:checked").each(function(i,ele){ 
            var parts = [];

            var block = $(ele).parent().parent();
            $(block).find("input[name=has_parts]:checked").each(function(j,ele1){
                parts.push($(ele1).val());                 
            }); 

            imgs[i] = {"src":$(ele).val(),"parts":parts.join(',')};
        }); 

        var data = {"ver":"1","op":"true","plant_id":plant_id,"saw":saw,"lifesort":lifesort,"leavestem":leavestem,"imgs":imgs};
        console.log(JSON.stringify(data));

        if(isRelease){
            $.post('/api/plant',JSON.stringify(data),function(result){
                $("#li_p_"+plant_id).remove();
                move_next_plant(); 
            });
        } else {
            $("#li_p_"+plant_id).remove();
            move_next_plant();
        }

        

        
    };

    var cancel = function(){
        var plant_id = location.hash.replace("#","");
        var data = '{"ver":"1","op":"false","plant_id":"'+ plant_id +'"}';

        if(isRelease){
            $.post('/api/plant',data,function(result){
                $("#li_p_"+plant_id).remove();
                move_next_plant(); 
            });
        } else {
            $("#li_p_"+plant_id).remove();
            move_next_plant();
        }
    };

    return {
        init:function(){
            render_plant_list();

            $("#load_random").click(function(){
                render_plant_list();
            });

            　　$("#plants").on("click", "a", function(){
                var plant_id = $(this).attr("href").replace('#','');
                　　render_plant(plant_id);
            　　}); 

            $("#btnSave").click(function(){                
                save(); 
            });

            $("#btnNext").click(function(){ 
                cancel();  
            });
        }
    };


});