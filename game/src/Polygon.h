#pragma once
#include "raylib.h"
#include "rlgl.h"           // Required for: Vertex definition
#include "raymath.h"
#define MAX_POINTS  11   
#include <vector>
#include <memory>

namespace kdn {
	class Polygon
	{
		int x;
		int y;
		std::vector<Vector2> points;
		std::vector<Vector2> uvpoints = {
			{0.00f,1.00f},
			{1.00f,1.00f},
			{1.00f,0.00f},
			{0.00f,0.00f},
			{0.00f,1.00f}
		};
		Texture texture;
	public:
		Polygon(int _x, int _y, std::vector<Vector2> _points, Texture _texture)
		{
			x = _x;
			y = _y;
			points = _points;
			texture = _texture;
		}
		void Update(int _x, int _y, std::vector<Vector2> _points)
		{
			x = _x;
			y = _y;
			points = _points;
		}
		void Draw()
		{
			DrawTexturePoly(texture, Vector2 { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f },
				points.data(), uvpoints.data(), MAX_POINTS, WHITE);
		}
		void DrawTexturePoly(Texture2D texture, Vector2 center, Vector2* points, Vector2* texcoords, int pointCount, Color tint)
		{
			rlSetTexture(texture.id);

			// Texturing is only supported on RL_QUADS
			rlBegin(RL_QUADS);

			rlColor4ub(tint.r, tint.g, tint.b, tint.a);

			for (int i = 0; i < pointCount - 1; i++)
			{
				rlTexCoord2f(0.5f, 0.5f);
				rlVertex2f(center.x, center.y);

				rlTexCoord2f(texcoords[i].x, texcoords[i].y);
				rlVertex2f(points[i].x + center.x, points[i].y + center.y);

				rlTexCoord2f(texcoords[i + 1].x, texcoords[i + 1].y);
				rlVertex2f(points[i + 1].x + center.x, points[i + 1].y + center.y);

				rlTexCoord2f(texcoords[i + 1].x, texcoords[i + 1].y);
				rlVertex2f(points[i + 1].x + center.x, points[i + 1].y + center.y);
			}
			rlEnd();

			rlSetTexture(0);
		}
	};
}