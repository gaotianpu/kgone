define(function(){
    return { 
        load_plants:function(start_id,callback){
            var data = {"data":[{"pk_id":"1","name_cn":"\u6cb9\u68d5"},{"pk_id":"2","name_cn":"\u5927\u4e1d\u8475"},{"pk_id":"3","name_cn":"\u4e91\u5357\u7701\u85e4"},{"pk_id":"4","name_cn":"\u4e8c\u5217\u7701\u85e4"},{"pk_id":"5","name_cn":"\u5c0f\u767d\u85e4"},{"pk_id":"6","name_cn":"\u67f3\u6761\u7701\u85e4"},{"pk_id":"7","name_cn":"\u6bdb\u9cde\u7701\u85e4"},{"pk_id":"8","name_cn":"\u76f4\u7acb\u7701\u85e4"},{"pk_id":"9","name_cn":"\u5927\u767d\u85e4"},{"pk_id":"10","name_cn":"\u957f\u97ad\u85e4"},{"pk_id":"11","name_cn":"\u7f05\u7538\u7701\u85e4"},{"pk_id":"12","name_cn":"\u6756\u85e4"},{"pk_id":"13","name_cn":"\u85cf\u6ce2\u7f57\u82b1"},{"pk_id":"14","name_cn":"\u5927\u53f6\u767e\u4e24\u91d1"},{"pk_id":"15","name_cn":"\u5c71\u8840\u4e39"},{"pk_id":"16","name_cn":"\u7ec6\u7f57\u4f1e"},{"pk_id":"17","name_cn":"\u7ec6\u67c4\u767e\u4e24\u91d1"},{"pk_id":"18","name_cn":"\u6bdb\u53f6\u96ea\u4e0b\u7ea2"},{"pk_id":"19","name_cn":"\u72ed\u53f6\u96ea\u4e0b\u7ea2"},{"pk_id":"20","name_cn":"\u77ed\u67c4\u6708\u6708\u7ea2"},{"pk_id":"21","name_cn":"\u8c79\u5b50\u773c\u775b\u679c"},{"pk_id":"22","name_cn":"\u725b\u820c\u8349"},{"pk_id":"23","name_cn":"\u5149\u53f6\u7c97\u7ce0\u6811"},{"pk_id":"24","name_cn":"\u8fa3\u6c41\u6811"},{"pk_id":"25","name_cn":"\u7f51\u8109\u6842"},{"pk_id":"26","name_cn":"\u94f6\u6728"},{"pk_id":"27","name_cn":"\u67f4\u6842"},{"pk_id":"28","name_cn":"\u5ddd\u6842"},{"pk_id":"29","name_cn":"\u5e7f\u897f\u9493\u6a1f"},{"pk_id":"30","name_cn":"\u7ea4\u6897\u5c71\u80e1\u6912"},{"pk_id":"31","name_cn":"\u6ce2\u5bc6\u9493\u6a1f"},{"pk_id":"32","name_cn":"\u65e0\u6bdb\u5c71\u80e1\u6912"},{"pk_id":"33","name_cn":"\u6da6\u6960"},{"pk_id":"34","name_cn":"\u7d2b\u53f6\u743c\u6960"},{"pk_id":"35","name_cn":"\u6bd5\u6f84\u8304"},{"pk_id":"36","name_cn":"\u5355\u53f6\u5434\u8438"},{"pk_id":"37","name_cn":"\u4e09\u6860\u82e6"},{"pk_id":"38","name_cn":"\u725b\u7d0f\u5434\u8438"},{"pk_id":"39","name_cn":"\u693f\u53f6\u82b1\u6912"},{"pk_id":"40","name_cn":"\u5f02\u53f6\u82b1\u6912"},{"pk_id":"41","name_cn":"\u82b1\u6912"},{"pk_id":"42","name_cn":"\u5cad\u5357\u82b1\u6912"},{"pk_id":"43","name_cn":"\u7af9\u53f6\u82b1\u6912"},{"pk_id":"44","name_cn":"\u5927\u53f6\u81ed\u82b1\u6912"},{"pk_id":"45","name_cn":"\u781a\u58f3\u82b1\u6912"},{"pk_id":"46","name_cn":"\u82b1\u83d6\u84b2"},{"pk_id":"47","name_cn":"\u641c\u5c71\u9ec4"},{"pk_id":"48","name_cn":"\u5355\u5305\u9e22\u5c3e"},{"pk_id":"49","name_cn":"\u674e\u53f6\u6986"},{"pk_id":"50","name_cn":"\u6bdb\u679d\u6986"}]};

    return callback(data);
            //  /api/plant/list?begin_id=0
            // return $.getJSON('/api/plant/list',{'begin_id':start_id},function(data){
            //     callback(data);
            // }); 
        }

    };
    
});

/*
Uncaught Error: Mismatched anonymous define() module

*/