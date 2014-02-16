#include <SDL2/SDL.h>
#include <GameEntity/GameEntity.h>
#include <QuadTreeNode>
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
		UpdateEntity(GameEntity*);
	
	private:
		GameEntity * CheckLeaf(const GameEntity*, QuadTreeNode * startNode = treeRoot);

	private:
		static const int QuadTreeMaxObjects = 32;
		static const int QuadTreeMaxDepth = 6;

	private:	
		QuadTreeNode treeRoot;
		std::vector<GameEntity*> allEntitiesInQuadTree;
};
