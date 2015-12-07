define(function(){
    var pageLoad = function(){ 
        // alert('upload');
       $("#typeId").val($("#typeId").attr("initval"));
   };

   var selectedChanged=function(){
       $("#typeId").change(function(data){
        var type = $(this).val();
        if(type!=='0'){
            $("#li_data_schema_link").html('<a href="/schema/' + type + '">数据规范</a>'); 
            $("#li_data_schema_link").show(); 

            $("#div_type").removeClass('has-error');
        }else{
            $("#li_data_schema_link").hide();
        }

    });
   };

   var validate = function(){
    $("#form_upload").submit(function(){
        var validate = true;
        if($("#typeId").val()===''  ){
            $("#div_type").addClass('has-error'); 
            validate = validate && false;
        }

        // alert($("#content").val());

        if($("#content").val()===''){
            $("#div_content").addClass('has-error'); 
            validate = validate && false;
        } 
        else{
            try{
                var data = JSON.parse($("#content").val()); 
            }catch(e){ 
                $("#div_content").addClass('has-error'); 
                validate = validate && false;
            }
        }

        // if($("#notes").val()===''){
        //     $("#div_notes").addClass('has-error'); 
        // } 

        return validate;
    });
};

return {
    init:function(){
        pageLoad();
        selectedChanged();
        validate();
    }
};



});   