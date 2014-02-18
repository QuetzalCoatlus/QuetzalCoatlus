#ifndef _QUADTREE_H_
	#define _QUADTREE_H_

#include <SDL.h>
#include "GameEntity.h"
#include "QuadTreeNode.h"
class QuadTree
{
	public:
		QuadTree(const int, const int);

	public:
		bool Insert(GameEntity*);
		bool Remove(GameEntity*);
		GameEntity * Collides(GameEntity*);
		void Update();

	private:
		void UpdateEntity(GameEntity*);
	
	private:
		GameEntity * CheckLeaf(const GameEntity*, QuadTreeNode*);
		bool InsertIntoFullQuad(GameEntity*,QuadTreeNode*);
		bool InsertIntoBranch(GameEntity*,QuadTreeNode*);
		bool InsertOnUpdate(GameEntity*,QuadTreeNode*);

	private:
		static const int QuadTreeMaxObjects = 32;
		static const int QuadTreeMaxDepth = 6;

	private:	
		QuadTreeNode * treeRoot;
		std::vector<GameEntity*> allEntitiesInQuadTree;
};

#endif