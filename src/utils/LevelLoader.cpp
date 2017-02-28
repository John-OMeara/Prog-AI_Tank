#include "utils/LevelLoader.h"

void operator >> (const YAML::Node& obstacleNode, ObstacleData& obstacle)
{
   obstacle.m_type = obstacleNode["type"].as<std::string>();
   obstacle.m_position.x = obstacleNode["position"]["x"].as<float>();
   obstacle.m_position.y = obstacleNode["position"]["y"].as<float>();
   obstacle.m_rotation = obstacleNode["rotation"].as<double>();
}

void operator >> (const YAML::Node& backgroundNode, BackgroundData& background)
{
   background.m_fileName = backgroundNode["file"].as<std::string>();
}

void operator >> (const YAML::Node& tankNode, TankData& tank)
{
	tank.m_position.x = tankNode["position"]["x"].as<float>();
	tank.m_position.y = tankNode["position"]["y"].as<float>();
	tank.m_maxProjectiles = tankNode["max_projectiles"].as<int>();
	tank.m_reloadTime = tankNode["reload_time"].as<int>();	
}

void operator >> (const YAML::Node& projectileNode, ProjectileData& projectile)
{	
	projectile.m_speed = projectileNode["speed"].as<double>();
	projectile.m_damage = projectileNode["damage"].as<int>();
}

void operator >> (const YAML::Node& nodeNode, NodeData& node)
{
	node.m_position.x = nodeNode["position"]["x"].as<float>();
	node.m_position.y = nodeNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
   levelNode["background"] >> level.m_background;

   levelNode["tank"] >> level.m_tank;

   levelNode["ai_tank"] >> level.m_aiTank;

   levelNode["projectile"] >> level.m_projectile;

   const YAML::Node& obstaclesNode = levelNode["obstacles"].as<YAML::Node>();
   for (unsigned i = 0; i < obstaclesNode.size(); ++i)
   {
	  ObstacleData obstacle;
	  obstaclesNode[i] >> obstacle;
	  level.m_obstacles.push_back(obstacle);
   }

   const YAML::Node& nodesNode = levelNode["nodes"].as<YAML::Node>();
   for (unsigned i = 0; i < nodesNode.size(); ++i)
   {
	   NodeData node;
	   nodesNode[i] >> node;
	   level.m_nodes.push_back(node);
   }
}

LevelLoader::LevelLoader()
{
}

bool LevelLoader::load(int nr, LevelData& level)
{
   std::stringstream ss;
   ss << resourcePath();
   ss << "levels/level";
   ss << nr;
   ss << ".yaml";

   try
   {
	  YAML::Node baseNode = YAML::LoadFile(ss.str());
	  if (baseNode.IsNull())
	  {
		  std::string message("file: " + ss.str() + " not found");
		  throw std::exception(message.c_str());
	  }
	  baseNode >> level;
   }
   catch(YAML::ParserException& e)
   {
       std::cout << e.what() << "\n";
       return false;
   }
   catch (std::exception& e)
   {
	   std::cout << e.what() << "\n";
	   return false;
   }

   return true;
}
