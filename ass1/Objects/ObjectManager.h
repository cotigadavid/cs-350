//
// Created by roland on 10/1/20.
//

#ifndef SIMPLE_SCENE_OBJECTMANAGER_H
#define SIMPLE_SCENE_OBJECTMANAGER_H

#include "stdafx.h"
#include "Object.h"
#include "CubeObject.h"
#include "SphereObject.h"
#include "TriangleObject.h"
#include "PlaneObject.h"
#include "RayObject.h"
#include "PointObject.h"

class ObjectManager {
    std::vector<SharedPtr<Object>> Objects;
public:

    //template<typename T>
    //SharedPtr<T> CreateObject();
    // 
    SharedPtr<Object> CreateObject();
    SharedPtr<CubeObject> CreateCubeObject();
    SharedPtr<SphereObject> CreateSphereObject();
    SharedPtr<TriangleObject> CreateTriangleObject();
    SharedPtr<PlaneObject> CreatePlaneObject();
    SharedPtr<RayObject> CreateRayObject();
    SharedPtr<PointObject> CreatePointObject();
    // Reminder: NEVER CREATE AN UPDATE FOR ALL OBJECTS HERE
    // need to rethink update if you do.

    void RenderAllObject();
};


#endif //SIMPLE_SCENE_OBJECTMANAGER_H
