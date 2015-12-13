-- MySQL dump 10.13  Distrib 5.5.27, for osx10.6 (i386)
--
-- Host: localhost    Database: kgb
-- ------------------------------------------------------
-- Server version	5.5.27

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `_entity_pages`
--

DROP TABLE IF EXISTS `_entity_pages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `_entity_pages` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `entity_id` int(11) DEFAULT NULL,
  `domain_main` varchar(20) DEFAULT NULL,
  `domain` varchar(50) DEFAULT NULL,
  `url` varchar(200) DEFAULT NULL,
  `uid` varchar(50) DEFAULT NULL,
  `target_device` varchar(11) DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `_entity_pages_user`
--

DROP TABLE IF EXISTS `_entity_pages_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `_entity_pages_user` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL DEFAULT '0',
  `entity_type_id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `entity_id` int(11) DEFAULT NULL,
  `entity_id_set` text,
  `url` varchar(100) DEFAULT NULL,
  `raw_entity_id` varchar(50) DEFAULT NULL,
  `domain_main` varchar(20) DEFAULT NULL,
  `domain` varchar(50) DEFAULT NULL,
  `jsonld` text,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `char_entities`
--

DROP TABLE IF EXISTS `char_entities`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `char_entities` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `char_one` varchar(2) DEFAULT NULL,
  `char_count` int(11) DEFAULT NULL,
  `entity_type_id` int(11) DEFAULT NULL,
  `entity_id` int(11) DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`),
  UNIQUE KEY `u` (`char_one`,`entity_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `entities`
--

DROP TABLE IF EXISTS `entities`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entities` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `type_id` int(11) DEFAULT NULL,
  `name` varchar(100) DEFAULT NULL,
  `jsonld` text,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`),
  UNIQUE KEY `u_typeId_name` (`type_id`,`name`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `entity_types`
--

DROP TABLE IF EXISTS `entity_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_types` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `name_cn` varchar(11) DEFAULT NULL,
  `category_1` int(11) NOT NULL DEFAULT '0',
  `category_2` int(11) NOT NULL DEFAULT '0',
  `schema_txt` text,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `entity_count` int(11) NOT NULL DEFAULT '0',
  `property_count` int(11) NOT NULL DEFAULT '0',
  `site_count` int(11) NOT NULL DEFAULT '0' COMMENT '站点数',
  `sites` varchar(800) NOT NULL DEFAULT '' COMMENT '融合站点',
  `last_stati` datetime DEFAULT NULL COMMENT '上次统计时间',
  PRIMARY KEY (`pk_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `upload_records`
--

DROP TABLE IF EXISTS `upload_records`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `upload_records` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(11) DEFAULT NULL,
  `type_id` int(11) DEFAULT NULL,
  `batch_no` varchar(20) DEFAULT NULL,
  `notes` varchar(300) DEFAULT NULL,
  `jsonld` text,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `entity_count` int(11) DEFAULT NULL,
  `property_count` int(11) DEFAULT NULL,
  PRIMARY KEY (`pk_id`),
  KEY `i_user_id` (`user_id`),
  KEY `i_type_id` (`type_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `pk_id` bigint(20) NOT NULL AUTO_INCREMENT,
  `mobile` varchar(50) DEFAULT NULL,
  `nick_name` varchar(50) DEFAULT NULL,
  `password` varchar(100) DEFAULT NULL,
  `creation_date` datetime DEFAULT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`),
  UNIQUE KEY `u_mobile` (`mobile`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-12-07 18:07:22
