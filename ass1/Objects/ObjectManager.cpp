//
// Created by roland on 10/1/20.
//
#include "ObjectManager.h"
#include "Renderer/Renderer.h"

void ObjectManager::RenderAllObject() {
	for (unsigned i = 0; i < Objects.size(); ++i)
	{
		for (auto& shader : Objects[i]->GetShaders())
		{
			if (Objects[i]->Renderable) {
				Renderer::Submit(
					shader,
					Objects[i]->GetVAO(),
					Objects[i]->GetTransformMatrix());
			}
		}
	}
}

//template<typename T>
//SharedPtr<T> ObjectManager::CreateObject() {
//    SharedPtr<T> obj = CreateSharedPtr<T>();
//    this->Objects.emplace_back(obj);
//    return obj;
//}

SharedPtr<Object> ObjectManager::CreateObject() {
	SharedPtr<Object> obj = CreateSharedPtr<Object>();
	this->Objects.emplace_back(obj);
	return obj;
}

SharedPtr<CubeObject> ObjectManager::CreateCubeObject()
{
	SharedPtr<CubeObject> obj = CreateSharedPtr<CubeObject>();
	this->Objects.emplace_back(obj);
	return obj;
}

SharedPtr<SphereObject> ObjectManager::CreateSphereObject()
{
	SharedPtr<SphereObject> obj = CreateSharedPtr<SphereObject>();
	this->Objects.emplace_back(obj);
	return obj;
}

SharedPtr<TriangleObject> ObjectManager::CreateTriangleObject()
{
	SharedPtr<TriangleObject> obj = CreateSharedPtr<TriangleObject>();
	this->Objects.emplace_back(obj);
	return obj;
}

SharedPtr<PlaneObject> ObjectManager::CreatePlaneObject()
{
	SharedPtr<PlaneObject> obj = CreateSharedPtr<PlaneObject>();
	this->Objects.emplace_back(obj);
	return obj;
}

SharedPtr<RayObject> ObjectManager::CreateRayObject()
{
	SharedPtr<RayObject> obj = CreateSharedPtr<RayObject>();
	this->Objects.emplace_back(obj);
	return obj;
}

SharedPtr<PointObject> ObjectManager::CreatePointObject()
{
	SharedPtr<PointObject> obj = CreateSharedPtr<PointObject>();
	this->Objects.emplace_back(obj);
	return obj;
}
