-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: SC_pro
-- ------------------------------------------------------
-- Server version	5.7.26-0ubuntu0.18.04.1

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
-- Table structure for table `Admin`
--

DROP TABLE IF EXISTS `Admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Admin` (
  `id` char(10) NOT NULL,
  `username` char(20) DEFAULT NULL,
  `password` char(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Admin`
--

LOCK TABLES `Admin` WRITE;
/*!40000 ALTER TABLE `Admin` DISABLE KEYS */;
INSERT INTO `Admin` VALUES ('tc0001','teacher0001','pw0001'),('tc0002','teacher0002','pw0002'),('tc0003','teacher0003','pw0003');
/*!40000 ALTER TABLE `Admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `C`
--

DROP TABLE IF EXISTS `C`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `C` (
  `Cno` char(10) NOT NULL,
  `name` char(20) DEFAULT NULL,
  `teacher` char(10) DEFAULT NULL,
  `credit` float DEFAULT NULL,
  PRIMARY KEY (`Cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `C`
--

LOCK TABLES `C` WRITE;
/*!40000 ALTER TABLE `C` DISABLE KEYS */;
INSERT INTO `C` VALUES ('C0001','数据库原理','郑吉平',3),('C0002','操作系统','刘亮',3.5),('C0003','模式识别','梁栋',2),('C0004','数字图像处理','朱旗',2);
/*!40000 ALTER TABLE `C` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S`
--

DROP TABLE IF EXISTS `S`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S` (
  `Sno` char(10) NOT NULL,
  `name` char(20) DEFAULT NULL,
  `sex` char(2) DEFAULT NULL,
  `age` smallint(6) DEFAULT NULL,
  `major` char(30) DEFAULT NULL,
  `password` char(20) DEFAULT NULL,
  PRIMARY KEY (`Sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S`
--

LOCK TABLES `S` WRITE;
/*!40000 ALTER TABLE `S` DISABLE KEYS */;
INSERT INTO `S` VALUES ('st0001','student0001','男',21,'物联网工程','pw0001'),('st0002','student0002','女',18,'物联网工程','pw0002');
/*!40000 ALTER TABLE `S` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `SC`
--

DROP TABLE IF EXISTS `SC`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SC` (
  `Sno` char(10) NOT NULL,
  `Cno` char(10) NOT NULL,
  `grade` smallint(6) DEFAULT NULL,
  PRIMARY KEY (`Sno`,`Cno`),
  KEY `Cno` (`Cno`),
  CONSTRAINT `SC_ibfk_1` FOREIGN KEY (`Sno`) REFERENCES `S` (`Sno`),
  CONSTRAINT `SC_ibfk_2` FOREIGN KEY (`Cno`) REFERENCES `C` (`Cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SC`
--

LOCK TABLES `SC` WRITE;
/*!40000 ALTER TABLE `SC` DISABLE KEYS */;
INSERT INTO `SC` VALUES ('st0001','C0001',98),('st0001','C0002',87),('st0001','C0003',94),('st0002','C0001',100),('st0002','C0002',79),('st0002','C0003',88);
/*!40000 ALTER TABLE `SC` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-06-01 20:14:32
