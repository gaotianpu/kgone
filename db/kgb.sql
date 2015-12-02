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
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`),
  UNIQUE KEY `u` (`char_one`,`entity_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1365 DEFAULT CHARSET=utf8;
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
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`)
) ENGINE=MyISAM AUTO_INCREMENT=144 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `entity_pages`
--

DROP TABLE IF EXISTS `entity_pages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_pages` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `entity_id` int(11) DEFAULT NULL,
  `domain_main` varchar(20) DEFAULT NULL,
  `domain` varchar(50) DEFAULT NULL,
  `url` varchar(200) DEFAULT NULL,
  `uid` varchar(50) DEFAULT NULL,
  `target_device` varchar(11) DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `entity_pages_tmp`
--

DROP TABLE IF EXISTS `entity_pages_tmp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_pages_tmp` (
  `pk_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
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
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`pk_id`)
) ENGINE=MyISAM AUTO_INCREMENT=275 DEFAULT CHARSET=utf8;
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
  `schema` text,
  `status` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `entity_count` int(11) DEFAULT NULL,
  `property_count` int(11) DEFAULT NULL,
  `site_count` int(11) DEFAULT NULL COMMENT '站点数',
  `sites` varchar(800) DEFAULT NULL COMMENT '融合站点',
  `last_stati` int(11) DEFAULT NULL COMMENT '上次统计时间',
  PRIMARY KEY (`pk_id`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-11-23 15:26:57
