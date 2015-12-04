<?php
require_once(ROOT_DIR."/private/dao/BaseDAO.inc");

require_once(ROOT_DIR."/private/model/CharEntities.inc");
require_once(ROOT_DIR."/private/dao/CharEntitiesDAO.inc");
require_once(ROOT_DIR."/private/logic/CharEntitiesLogic.inc");

require_once(ROOT_DIR."/private/model/Entities.inc");
require_once(ROOT_DIR."/private/dao/EntitiesDAO.inc");
require_once(ROOT_DIR."/private/logic/EntitiesLogic.inc");

require_once(ROOT_DIR."/private/model/EntityPages.inc");
require_once(ROOT_DIR."/private/dao/EntityPagesDAO.inc");
require_once(ROOT_DIR."/private/logic/EntityPagesLogic.inc");

require_once(ROOT_DIR."/private/model/EntityPagesTmp.inc");
require_once(ROOT_DIR."/private/dao/EntityPagesTmpDAO.inc");
require_once(ROOT_DIR."/private/logic/EntityPagesTmpLogic.inc");

require_once(ROOT_DIR."/private/model/EntityTypes.inc");
require_once(ROOT_DIR."/private/dao/EntityTypesDAO.inc");
require_once(ROOT_DIR."/private/logic/EntityTypesLogic.inc");

require_once(ROOT_DIR."/private/model/UploadBatches.inc");
require_once(ROOT_DIR."/private/dao/UploadBatchesDAO.inc");
require_once(ROOT_DIR."/private/logic/UploadBatchesLogic.inc");

require_once(ROOT_DIR."/private/model/Users.inc");
require_once(ROOT_DIR."/private/dao/UsersDAO.inc");
require_once(ROOT_DIR."/private/logic/UserLogic.inc");

require_once(ROOT_DIR."/private/controller/BaseController.inc");
require_once(ROOT_DIR."/private/controller/IndexController.inc");
require_once(ROOT_DIR."/private/controller/RegisterController.inc");
require_once(ROOT_DIR."/private/controller/LoginController.inc"); 
require_once(ROOT_DIR."/private/controller/EntityTypeController.inc");
require_once(ROOT_DIR."/private/controller/EntityController.inc");
require_once(ROOT_DIR."/private/controller/UploadController.inc");
require_once(ROOT_DIR."/private/controller/FeedController.inc");
require_once(ROOT_DIR."/private/controller/DownloadController.inc");
require_once(ROOT_DIR."/private/controller/SchemaController.inc");

?>
