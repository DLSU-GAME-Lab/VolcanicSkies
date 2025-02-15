﻿/*
 * Volcanic Skies
 * Copyright (C) 2024 P. Cilliers Pretorius, University of Cape Town
 *
 * This file is part of the Volcanic Skies project.
 *
 * Volcanic Skies is free software: you can redistribute it and/or modify it under the terms 
 * of the GNU General Public License (GPL) as published by the Free Software 
 * Foundation, either version 2 of the License, or (at your discretion) any later version.
 *
 * Volcanic Skies is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with 
 * Volcanic Skies in the LICENSE file. If not, see <https://www.gnu.org/licenses/>.
 *
 * Additional information and disclaimers regarding liability and third-party 
 * components can be found in the NOTICE file included with this project.
 *
 */
#ifndef PWM_UTILS_SETTINGS_H
#define PWM_UTILS_SETTINGS_H

#include "json.hpp"
#include "planet.h"
#include "sun.h"
#include <vector>

namespace PWM{
    namespace Utils{
        class settings {
        public:
            settings();
            settings(std::string file);

            int writeSettings(std::string file) const;

            bool operator==(const settings& other) const;
            bool operator!=(const settings& other) const;

            //advectionEngine
            bool coriolis = true;

            //atmosphericHeatingEngine
            float aheSurfaceFluxRatio = 1.5;
            float aheThreshold = 0.0001;

            //heatDissipationEngine
            float hdeCoefficient = -1;

            //phaseTransitionEngine
            bool pteDoEvaporation = true;
            bool pteDoCondensation = true;
            bool pteDoEvaporationHeatExchange = true;
            bool pteDoCondensationHeatExchange = true;
            bool pteDoParticleCondensation = true;
            float pteEvaporationCoefficient = 0.1;
            float pteCondensationCoefficient = 0.1;

            //terrainHeatingEngine
            float theHeatLossCoefficient = 0.3;

            //verticalCouplingEngine
            float vceConvectCouplingCoeff = 0.0005; // 0.001; // 0.0005;
            float vcePressureCouplingCoeff = 0.0005; // 0.005
            float vcePressureUpliftCoeff = 0.0005; // 0.0005
            bool vcePerformPressureUplift = true;
            // JG changes

            //worldEngine
            float weDt = 5.0;

            //worldModel
            PWM::Model::planet P;
            std::vector<PWM::Model::sun<float>> suns;
            float wmThreshold = 0.25;
            float atmoTopHeight = 12000;
            float actualSize = 50000;
            int gridWidth = 60;
            int terrainCellWidth = 512;
            int maxLayers = 10;

            //Plume settings
            float plumeDT = 0.002;
            std::string terrainFile;
            std::string smokeTextureFile;
            int subspheres = 500;
            int subsubspheres = 0;
            float initialPlumeSpeed = 150;
            float initialPlumeDensity = 200;
            float ventRay = 100;
            float ventAltitude = 0;
            float initialEjectionAngle = 0;
        };
        
        //JSON lib interaction functions
    inline void to_json(nlohmann::json& j, const settings& s);
    inline void from_json(const nlohmann::json& j, settings& s);
    }
}

#endif // PWM_UTILS_SETTINGS_H
