// generated by Fast Light User Interface Designer (fluid) version 1.0105

#include "psEditorGUI.h"

Fl_Menu_Bar *MainMenu=(Fl_Menu_Bar *)0;

Fl_Menu_Item menu_MainMenu[] = {
 {"&File", 0,  0, 0, 64, 0, 0, 14, 56},
 {"&New", 0,  (Fl_Callback*)psEditorGUI_New, 0, 0, 0, 0, 14, 56},
 {"&Open...", 0,  (Fl_Callback*)psEditorGUI_Open, 0, 0, 0, 0, 14, 56},
 {"Open &Previous", 0,  0, 0, 64, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {"item", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {"&Import...", 0,  (Fl_Callback*)psEditorGUI_Import, 0, 128, 0, 0, 14, 56},
 {"&Save", 0,  (Fl_Callback*)psEditorGUI_Save, 0, 0, 0, 0, 14, 56},
 {"Save &As...", 0,  (Fl_Callback*)psEditorGUI_SaveAs, 0, 128, 0, 0, 14, 56},
 {"&Quit", 0,  (Fl_Callback*)psEditorGUI_Quit, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {"&View", 0,  0, 0, 64, 0, 0, 14, 56},
 {"&Compass", 0,  (Fl_Callback*)psEditorGUI_Compass, 0, 128, 0, 0, 14, 56},
 {"&XY Grid", 0,  (Fl_Callback*)psEditorGUI_XYGrid, 0, 0, 0, 0, 14, 56},
 {"&YZ Grid", 0,  (Fl_Callback*)psEditorGUI_YZGrid, 0, 0, 0, 0, 14, 56},
 {"X&Z Grid", 0,  (Fl_Callback*)psEditorGUI_XZGrid, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Button *Layers_DeleteButton=(Fl_Button *)0;

Fl_Button *Layers_RenameButton=(Fl_Button *)0;

Fl_Browser *Layers=(Fl_Browser *)0;

Fl_Button *Layers_HideButton=(Fl_Button *)0;

Fl_DT_Window<dtABC::Widget> *viewWidget=(Fl_DT_Window<dtABC::Widget> *)0;

Fl_Tabs *ParameterTabs=(Fl_Tabs *)0;

Fl_Choice *Particles_Alignment=(Fl_Choice *)0;

Fl_Menu_Item menu_Particles_Alignment[] = {
 {"Billboard", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Fixed", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Choice *Particles_Shape=(Fl_Choice *)0;

Fl_Menu_Item menu_Particles_Shape[] = {
 {"Point", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Quad", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Quad Tri Strip", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Hexagon", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Line", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Value_Input *Particles_Lifetime=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MinSize=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MaxSize=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_Radius=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_Mass=(Fl_Value_Input *)0;

Fl_Input *Particles_Texture=(Fl_Input *)0;

Fl_Check_Button *Particles_Emissive=(Fl_Check_Button *)0;

Fl_Check_Button *Particles_Lighting=(Fl_Check_Button *)0;

Fl_Value_Input *Particles_MinR=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MinG=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MinB=(Fl_Value_Input *)0;

Fl_Button *Particles_MinColor=(Fl_Button *)0;

Fl_Value_Input *Particles_MinAlpha=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MaxR=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MaxG=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_MaxB=(Fl_Value_Input *)0;

Fl_Button *Particles_MaxColor=(Fl_Button *)0;

Fl_Value_Input *Particles_MaxAlpha=(Fl_Value_Input *)0;

Fl_Check_Button *Particles_Emitter_Endless=(Fl_Check_Button *)0;

Fl_Value_Input *Particles_Emitter_Lifetime=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_Emitter_StartTime=(Fl_Value_Input *)0;

Fl_Value_Input *Particles_Emitter_ResetTime=(Fl_Value_Input *)0;

TexturePreview *Particles_TexturePreview=(TexturePreview *)0;

Fl_Group *RandomRateCounterParameters=(Fl_Group *)0;

Fl_Value_Input *RandomRateCounter_MinRate=(Fl_Value_Input *)0;

Fl_Value_Input *RandomRateCounter_MaxRate=(Fl_Value_Input *)0;

Fl_Menu_Item menu_Counter[] = {
 {"Random Rate Counter", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Group *SegmentPlacerParameters=(Fl_Group *)0;

Fl_Value_Input *SegmentPlacer_A_X=(Fl_Value_Input *)0;

Fl_Value_Input *SegmentPlacer_A_Y=(Fl_Value_Input *)0;

Fl_Value_Input *SegmentPlacer_A_Z=(Fl_Value_Input *)0;

Fl_Value_Input *SegmentPlacer_B_X=(Fl_Value_Input *)0;

Fl_Value_Input *SegmentPlacer_B_Y=(Fl_Value_Input *)0;

Fl_Value_Input *SegmentPlacer_B_Z=(Fl_Value_Input *)0;

Fl_Group *SectorPlacerParameters=(Fl_Group *)0;

Fl_Value_Input *SectorPlacer_X=(Fl_Value_Input *)0;

Fl_Value_Input *SectorPlacer_Y=(Fl_Value_Input *)0;

Fl_Value_Input *SectorPlacer_Z=(Fl_Value_Input *)0;

Fl_Value_Input *SectorPlacer_MinRadius=(Fl_Value_Input *)0;

Fl_Value_Input *SectorPlacer_MaxRadius=(Fl_Value_Input *)0;

Fl_Value_Input *SectorPlacer_MinPhi=(Fl_Value_Input *)0;

Fl_Value_Input *SectorPlacer_MaxPhi=(Fl_Value_Input *)0;

Fl_Group *PointPlacerParameters=(Fl_Group *)0;

Fl_Value_Input *PointPlacer_X=(Fl_Value_Input *)0;

Fl_Value_Input *PointPlacer_Y=(Fl_Value_Input *)0;

Fl_Value_Input *PointPlacer_Z=(Fl_Value_Input *)0;

Fl_Group *MultiSegmentPlacerParameters=(Fl_Group *)0;

Fl_Browser *MultiSegmentPlacer_Vertices=(Fl_Browser *)0;

Fl_Button *MultiSegmentPlacer_DeleteVertex=(Fl_Button *)0;

Fl_Group *MultiSegmentPlacer_VertexParameters=(Fl_Group *)0;

Fl_Value_Input *MultiSegmentPlacer_X=(Fl_Value_Input *)0;

Fl_Value_Input *MultiSegmentPlacer_Y=(Fl_Value_Input *)0;

Fl_Value_Input *MultiSegmentPlacer_Z=(Fl_Value_Input *)0;

Fl_Choice *Placer_Type=(Fl_Choice *)0;

Fl_Menu_Item menu_Placer_Type[] = {
 {"Point Placer", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Sector Placer", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Segment Placer", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Multi Segment Placer", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Group *RadialShooterParameters=(Fl_Group *)0;

Fl_Value_Input *RadialShooter_MinTheta=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MaxTheta=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MinPhi=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MaxPhi=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MinInitialSpeed=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MaxInitialSpeed=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MinInitialRotationalSpeedX=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MinInitialRotationalSpeedY=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MinInitialRotationalSpeedZ=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MaxInitialRotationalSpeedX=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MaxInitialRotationalSpeedY=(Fl_Value_Input *)0;

Fl_Value_Input *RadialShooter_MaxInitialRotationalSpeedZ=(Fl_Value_Input *)0;

Fl_Menu_Item menu_Shooter[] = {
 {"Radial Shooter", 0,  0, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Browser *Program_Operators=(Fl_Browser *)0;

Fl_Button *Program_DeleteOperator=(Fl_Button *)0;

Fl_Group *FluidFrictionParameters=(Fl_Group *)0;

Fl_Value_Input *FluidFriction_Density=(Fl_Value_Input *)0;

Fl_Value_Input *FluidFriction_Viscosity=(Fl_Value_Input *)0;

Fl_Value_Input *FluidFriction_OverrideRadius=(Fl_Value_Input *)0;

Fl_Group *ForceParameters=(Fl_Group *)0;

Fl_Value_Input *Force_X=(Fl_Value_Input *)0;

Fl_Value_Input *Force_Y=(Fl_Value_Input *)0;

Fl_Value_Input *Force_Z=(Fl_Value_Input *)0;

Fl_Group *AccelerationParameters=(Fl_Group *)0;

Fl_Value_Input *Acceleration_X=(Fl_Value_Input *)0;

Fl_Value_Input *Acceleration_Y=(Fl_Value_Input *)0;

Fl_Value_Input *Acceleration_Z=(Fl_Value_Input *)0;

Fl_Double_Window* make_window() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(1408, 594, "Particle System Editor");
    w = o;
    { Fl_Menu_Bar* o = MainMenu = new Fl_Menu_Bar(5, 5, 1400, 25);
      o->menu(menu_MainMenu);
    }
    { Fl_Tile* o = new Fl_Tile(5, 35, 1405, 555);
      o->box(FL_UP_FRAME);
      { Fl_Group* o = new Fl_Group(719, 35, 185, 290);
        o->box(FL_DOWN_BOX);
        { Fl_Button* o = new Fl_Button(729, 255, 30, 30, "@+");
          o->tooltip("Add new Layer");
          o->callback((Fl_Callback*)psEditorGUI_NewLayer);
        }
        { Fl_Button* o = Layers_DeleteButton = new Fl_Button(764, 255, 30, 30, "@line");
          o->tooltip("Delete selected Layer");
          o->callback((Fl_Callback*)psEditorGUI_DeleteLayer);
        }
        { Fl_Button* o = Layers_RenameButton = new Fl_Button(729, 290, 65, 30, "Rename");
          o->tooltip("Rename selected Layer");
          o->callback((Fl_Callback*)psEditorGUI_RenameLayer);
        }
        { Fl_Browser* o = Layers = new Fl_Browser(724, 85, 180, 165, "Layers");
          o->type(2);
          o->callback((Fl_Callback*)psEditorGUI_LayerSelect);
          o->align(FL_ALIGN_TOP);
        }
        { Fl_Button* o = Layers_HideButton = new Fl_Button(799, 255, 40, 30, "Hide");
          o->tooltip("Toggle the visibility of the selected Layer");
          o->callback((Fl_Callback*)psEditorGUI_HideLayer);
        }
        { Fl_Box* o = new Fl_Box(839, 35, 45, 290);
          o->hide();
          Fl_Group::current()->resizable(o);
        }
        o->end();
      }
      { Fl_DT_Window<dtABC::Widget>* o = viewWidget = new Fl_DT_Window<dtABC::Widget>(5, 35, 714, 555);
        o->box(FL_DOWN_BOX);
        o->color(FL_BACKGROUND_COLOR);
        o->selection_color(FL_BACKGROUND_COLOR);
        o->labeltype(FL_NORMAL_LABEL);
        o->labelfont(0);
        o->labelsize(14);
        o->labelcolor(FL_BLACK);
        o->align(FL_ALIGN_CENTER);
        o->when(FL_WHEN_RELEASE);
      }
      { Fl_Tabs* o = ParameterTabs = new Fl_Tabs(904, 39, 495, 549);
        { Fl_Group* o = new Fl_Group(904, 60, 490, 515, "Particles");
          { Fl_Choice* o = Particles_Alignment = new Fl_Choice(979, 70, 95, 25, "Alignment");
            o->down_box(FL_BORDER_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetAlignment);
            o->menu(menu_Particles_Alignment);
          }
          { Fl_Choice* o = Particles_Shape = new Fl_Choice(979, 105, 130, 25, "Shape");
            o->down_box(FL_BORDER_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetShape);
            o->menu(menu_Particles_Shape);
          }
          { Fl_Value_Input* o = Particles_Lifetime = new Fl_Value_Input(979, 140, 60, 25, "Life(sec)");
            o->tooltip("The lifetime of each particle (seconds)");
            o->maximum(1000);
            o->step(0.01);
            o->value(2);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetLifetime);
          }
          { Fl_Value_Input* o = Particles_MinSize = new Fl_Value_Input(979, 225, 60, 25, "Size (m)");
            o->tooltip("Size at start of lifetime");
            o->maximum(1000);
            o->step(0.01);
            o->value(0.2);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetMinSize);
          }
          { Fl_Value_Input* o = Particles_MaxSize = new Fl_Value_Input(1059, 225, 60, 25, "to");
            o->tooltip("Size at end of lifetime");
            o->maximum(1000);
            o->step(0.01);
            o->value(0.2);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetMaxSize);
          }
          { Fl_Value_Input* o = Particles_Radius = new Fl_Value_Input(979, 168, 60, 25, "Radius");
            o->maximum(10);
            o->step(0.01);
            o->value(0.2);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetRadius);
          }
          { Fl_Value_Input* o = Particles_Mass = new Fl_Value_Input(979, 196, 60, 25, "Mass");
            o->maximum(10);
            o->step(0.01);
            o->value(0.1);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetMass);
          }
          { Fl_Input* o = Particles_Texture = new Fl_Input(979, 269, 291, 25, "Texture");
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetTexture);
          }
          { Fl_Button* o = new Fl_Button(1274, 269, 30, 25, "...");
            o->callback((Fl_Callback*)psEditorGUI_Particles_ChooseTexture);
          }
          { Fl_Check_Button* o = Particles_Emissive = new Fl_Check_Button(1074, 147, 95, 25, "Emissive");
            o->down_box(FL_DOWN_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetEmissive);
          }
          { Fl_Check_Button* o = Particles_Lighting = new Fl_Check_Button(1074, 172, 20, 25, "Lighting");
            o->down_box(FL_DOWN_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Particles_SetLighting);
          }
          { Fl_Group* o = new Fl_Group(979, 316, 140, 125);
            o->box(FL_ENGRAVED_BOX);
            { Fl_Value_Input* o = Particles_MinR = new Fl_Value_Input(999, 322, 80, 25, "R");
              o->tooltip("Start color Red");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMinR);
            }
            { Fl_Value_Input* o = Particles_MinG = new Fl_Value_Input(999, 352, 80, 25, "G");
              o->tooltip("Start color green");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMinG);
            }
            { Fl_Value_Input* o = Particles_MinB = new Fl_Value_Input(999, 382, 80, 25, "B");
              o->tooltip("Start color blue");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMinB);
            }
            { Fl_Button* o = Particles_MinColor = new Fl_Button(1084, 322, 25, 85, "...");
              o->callback((Fl_Callback*)psEditorGUI_Particles_ChooseMinColor);
            }
            { Fl_Value_Input* o = Particles_MinAlpha = new Fl_Value_Input(998, 411, 80, 25, "A");
              o->tooltip("Alpha value at start of lifetime");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMinAlpha);
            }
            o->end();
          }
          new Fl_Box(934, 367, 45, 25, "Color");
          { Fl_Group* o = new Fl_Group(1144, 316, 140, 125);
            o->box(FL_ENGRAVED_BOX);
            { Fl_Value_Input* o = Particles_MaxR = new Fl_Value_Input(1164, 322, 80, 25, "R");
              o->tooltip("End color red");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMaxR);
            }
            { Fl_Value_Input* o = Particles_MaxG = new Fl_Value_Input(1164, 352, 80, 25, "G");
              o->tooltip("End color green");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMaxG);
            }
            { Fl_Value_Input* o = Particles_MaxB = new Fl_Value_Input(1164, 382, 80, 25, "B");
              o->tooltip("End color blue");
              o->step(0.01);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMaxB);
            }
            { Fl_Button* o = Particles_MaxColor = new Fl_Button(1249, 322, 25, 85, "...");
              o->callback((Fl_Callback*)psEditorGUI_Particles_ChooseMaxColor);
            }
            { Fl_Value_Input* o = Particles_MaxAlpha = new Fl_Value_Input(1165, 411, 80, 25, "A");
              o->tooltip("Alpha value at end of lifetime");
              o->step(0.01);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetMaxAlpha);
            }
            o->end();
          }
          new Fl_Box(1119, 363, 25, 25, "to");
          { Fl_Group* o = new Fl_Group(979, 453, 305, 110, "Emitter");
            o->box(FL_ENGRAVED_BOX);
            o->align(FL_ALIGN_LEFT);
            { Fl_Check_Button* o = Particles_Emitter_Endless = new Fl_Check_Button(1196, 500, 80, 25, "Forever");
              o->tooltip("Does the emitter endlessly emit particles?");
              o->down_box(FL_DOWN_BOX);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetEmitterEndless);
            }
            { Fl_Value_Input* o = Particles_Emitter_Lifetime = new Fl_Value_Input(1096, 465, 80, 25, "Life(sec)");
              o->tooltip("The emitter\'s lifetime (in seconds)");
              o->maximum(10);
              o->step(0.01);
              o->value(5);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetEmitterLifetime);
            }
            { Fl_Value_Input* o = Particles_Emitter_StartTime = new Fl_Value_Input(1096, 495, 80, 25, "Start Time (sec)");
              o->tooltip("The amount of delay before emitting");
              o->maximum(10);
              o->step(0.01);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetEmitterStartTime);
            }
            { Fl_Value_Input* o = Particles_Emitter_ResetTime = new Fl_Value_Input(1096, 526, 80, 25, "Reset Time (sec)");
              o->tooltip("How long before the emitter resets (seconds)");
              o->maximum(10);
              o->step(0.01);
              o->callback((Fl_Callback*)psEditorGUI_Particles_SetEmitterResetTime);
            }
            o->end();
          }
          { TexturePreview* o = Particles_TexturePreview = new TexturePreview(1177, 105, 128, 128, "Texture Preview");
            o->box(FL_DOWN_BOX);
            o->color(FL_BACKGROUND_COLOR);
            o->selection_color(FL_BACKGROUND_COLOR);
            o->labeltype(FL_NORMAL_LABEL);
            o->labelfont(0);
            o->labelsize(14);
            o->labelcolor(FL_BLACK);
            o->align(FL_ALIGN_TOP);
            o->when(FL_WHEN_RELEASE);
          }
          o->end();
        }
        { Fl_Group* o = new Fl_Group(904, 60, 490, 515, "Counter");
          o->hide();
          { Fl_Group* o = RandomRateCounterParameters = new Fl_Group(974, 308, 290, 157, "Random Rate Counter Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Value_Input* o = RandomRateCounter_MinRate = new Fl_Value_Input(1144, 350, 80, 25, "Min. Rate (particles/sec)");
              o->tooltip("The minimum number of particles/sec output from the Emitter");
              o->maximum(1000);
              o->step(0.1);
              o->value(20);
              o->callback((Fl_Callback*)psEditorGUI_RandomRateCounter_SetMinRate);
            }
            { Fl_Value_Input* o = RandomRateCounter_MaxRate = new Fl_Value_Input(1144, 385, 80, 25, "Max. Rate (particles/sec)");
              o->tooltip("The maximum number of particles/sec output from the Emitter");
              o->maximum(1000);
              o->step(0.1);
              o->value(30);
              o->callback((Fl_Callback*)psEditorGUI_RandomRateCounter_SetMaxRate);
            }
            o->end();
          }
          { Fl_Choice* o = new Fl_Choice(1064, 123, 180, 25, "Counter Type");
            o->down_box(FL_BORDER_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Counter_SetType);
            o->menu(menu_Counter);
          }
          o->end();
        }
        { Fl_Group* o = new Fl_Group(904, 60, 490, 515, "Placer");
          o->hide();
          { Fl_Group* o = SegmentPlacerParameters = new Fl_Group(924, 305, 350, 160, "Segment Placer Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Group* o = new Fl_Group(944, 335, 145, 103, "Vertex A");
              o->box(FL_ENGRAVED_BOX);
              { Fl_Value_Input* o = SegmentPlacer_A_X = new Fl_Value_Input(989, 345, 80, 25, "X");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->value(-1);
                o->callback((Fl_Callback*)psEditor_SegmentPlacer_VertexA_SetX);
              }
              { Fl_Value_Input* o = SegmentPlacer_A_Y = new Fl_Value_Input(989, 375, 80, 25, "Y");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditor_SegmentPlacer_VertexA_SetY);
              }
              { Fl_Value_Input* o = SegmentPlacer_A_Z = new Fl_Value_Input(989, 405, 80, 25, "Z");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditor_SegmentPlacer_VertexA_SetZ);
              }
              o->end();
            }
            { Fl_Group* o = new Fl_Group(1114, 333, 120, 105, "Vertex B");
              o->box(FL_ENGRAVED_BOX);
              { Fl_Value_Input* o = SegmentPlacer_B_X = new Fl_Value_Input(1134, 345, 80, 25, "X");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->value(1);
                o->callback((Fl_Callback*)psEditor_SegmentPlacer_VertexB_SetX);
              }
              { Fl_Value_Input* o = SegmentPlacer_B_Y = new Fl_Value_Input(1134, 375, 80, 25, "Y");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditor_SegmentPlacer_VertexB_SetY);
              }
              { Fl_Value_Input* o = SegmentPlacer_B_Z = new Fl_Value_Input(1134, 405, 80, 25, "Z");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditor_SegmentPlacer_VertexB_SetZ);
              }
              o->end();
            }
            o->end();
          }
          { Fl_Group* o = SectorPlacerParameters = new Fl_Group(909, 305, 465, 158, "Sector Placer Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Group* o = new Fl_Group(924, 330, 115, 108, "Center");
              o->box(FL_ENGRAVED_BOX);
              { Fl_Value_Input* o = SectorPlacer_X = new Fl_Value_Input(947, 340, 80, 25, "X");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_Center_SetX);
              }
              { Fl_Value_Input* o = SectorPlacer_Y = new Fl_Value_Input(947, 372, 80, 25, "Y");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_Center_SetY);
              }
              { Fl_Value_Input* o = SectorPlacer_Z = new Fl_Value_Input(945, 403, 80, 25, "Z");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_Center_SetZ);
              }
              o->end();
            }
            { Fl_Value_Input* o = SectorPlacer_MinRadius = new Fl_Value_Input(1124, 355, 80, 25, "Min. Radius");
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_SetMinRadius);
            }
            { Fl_Value_Input* o = SectorPlacer_MaxRadius = new Fl_Value_Input(1124, 386, 80, 25, "Max. Radius");
              o->maximum(10);
              o->step(0.1);
              o->value(1);
              o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_SetMaxRadius);
            }
            { Fl_Value_Input* o = SectorPlacer_MinPhi = new Fl_Value_Input(1274, 355, 80, 25, "Min. Phi");
              o->maximum(6.2832);
              o->step(0.01);
              o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_SetMinPhi);
            }
            { Fl_Value_Input* o = SectorPlacer_MaxPhi = new Fl_Value_Input(1274, 386, 80, 25, "Max. Phi");
              o->maximum(6.2832);
              o->step(0.01);
              o->value(6.2832);
              o->callback((Fl_Callback*)psEditorGUI_SectorPlacer_SetMaxPhi);
            }
            o->end();
          }
          { Fl_Group* o = PointPlacerParameters = new Fl_Group(928, 303, 341, 162, "Point Placer Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Value_Input* o = PointPlacer_X = new Fl_Value_Input(1063, 335, 80, 25, "X");
              o->minimum(-10);
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_PointPlacer_SetX);
            }
            { Fl_Value_Input* o = PointPlacer_Y = new Fl_Value_Input(1063, 365, 80, 25, "Y");
              o->minimum(-10);
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_PointPlacer_SetY);
            }
            { Fl_Value_Input* o = PointPlacer_Z = new Fl_Value_Input(1063, 395, 80, 25, "Z");
              o->minimum(-10);
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_PointPlacer_SetZ);
            }
            o->end();
          }
          { Fl_Group* o = MultiSegmentPlacerParameters = new Fl_Group(909, 305, 380, 160, "Multi Segment Placer Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Browser* o = MultiSegmentPlacer_Vertices = new Fl_Browser(919, 315, 170, 105, "Vertices");
              o->type(2);
              o->callback((Fl_Callback*)psEditorGUI_MultiSegmentPlacer_VerticesChanged);
            }
            { Fl_Button* o = new Fl_Button(1094, 365, 115, 25, "Add Vertex");
              o->callback((Fl_Callback*)psEditorGUI_MultiSegmentPlacer_AddVertex);
            }
            { Fl_Button* o = MultiSegmentPlacer_DeleteVertex = new Fl_Button(1094, 395, 115, 25, "Delete Vertex");
              o->callback((Fl_Callback*)psEditorGUI_MultiSegmentPlacer_DeleteVertex);
            }
            { Fl_Group* o = MultiSegmentPlacer_VertexParameters = new Fl_Group(1249, 315, 40, 105, "Vertex Parameters");
              o->box(FL_ENGRAVED_BOX);
              o->align(FL_ALIGN_BOTTOM);
              o->hide();
              { Fl_Value_Input* o = MultiSegmentPlacer_X = new Fl_Value_Input(1274, 325, 15, 25, "X");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_MultiSegmentPlacer_Vertex_SetX);
              }
              { Fl_Value_Input* o = MultiSegmentPlacer_Y = new Fl_Value_Input(1274, 355, 15, 25, "Y");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_MultiSegmentPlacer_Vertex_SetY);
              }
              { Fl_Value_Input* o = MultiSegmentPlacer_Z = new Fl_Value_Input(1274, 385, 15, 25, "Z");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_MultiSegmentPlacer_Vertex_SetZ);
              }
              o->end();
            }
            o->end();
          }
          { Fl_Choice* o = Placer_Type = new Fl_Choice(1069, 133, 155, 25, "Placer Type");
            o->down_box(FL_BORDER_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Placer_SetType);
            o->menu(menu_Placer_Type);
          }
          o->end();
        }
        { Fl_Group* o = new Fl_Group(904, 60, 490, 515, "Shooter");
          o->hide();
          { Fl_Group* o = RadialShooterParameters = new Fl_Group(909, 188, 460, 387);
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            { Fl_Group* o = new Fl_Group(1113, 201, 163, 64, "Elevation Range");
              o->tooltip("The elevation range the Shooter will send each particle. 0=up, 3.14=down");
              o->box(FL_ENGRAVED_FRAME);
              o->align(FL_ALIGN_LEFT);
              { Fl_Value_Input* o = RadialShooter_MinTheta = new Fl_Value_Input(1186, 205, 85, 25, "Min (rad)");
                o->tooltip("The minimum elevation (0=up, 3.14=down)");
                o->minimum(-3.1416);
                o->maximum(3.1416);
                o->step(0.01);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMinTheta);
              }
              { Fl_Value_Input* o = RadialShooter_MaxTheta = new Fl_Value_Input(1186, 235, 85, 25, "Max (rad)");
                o->tooltip("The maximum elevation (0=up, 3.14=down)");
                o->minimum(-3.1416);
                o->maximum(3.1416);
                o->step(0.01);
                o->value(0.3927);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMaxTheta);
              }
              o->end();
            }
            { Fl_Group* o = new Fl_Group(1114, 275, 163, 64, "Azimuth Range");
              o->tooltip("The azimuth range the Shooter will send each particle. 0 = X axis, 3.14 = -X \
axis");
              o->box(FL_ENGRAVED_FRAME);
              o->align(FL_ALIGN_LEFT);
              { Fl_Value_Input* o = RadialShooter_MinPhi = new Fl_Value_Input(1187, 280, 85, 25, "Min (rad)");
                o->tooltip("The minimum azimuth (0=down the X+ axis)");
                o->minimum(-6.2832);
                o->maximum(6.2832);
                o->step(0.01);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMinPhi);
              }
              { Fl_Value_Input* o = RadialShooter_MaxPhi = new Fl_Value_Input(1187, 310, 85, 25, "Max (rad)");
                o->tooltip("The maximum azimuth (0=down the -X axis)");
                o->minimum(-6.2832);
                o->maximum(6.2832);
                o->step(0.01);
                o->value(6.2832);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMaxPhi);
              }
              o->end();
            }
            { Fl_Group* o = new Fl_Group(1115, 349, 163, 64, "Initial Velocity Range");
              o->tooltip("The initial velocity range the Shooter will send each particle");
              o->box(FL_ENGRAVED_FRAME);
              o->align(FL_ALIGN_LEFT);
              { Fl_Value_Input* o = RadialShooter_MinInitialSpeed = new Fl_Value_Input(1188, 354, 85, 25, "Min (m/s)");
                o->tooltip("The minimum starting velocity of each particle");
                o->maximum(1000);
                o->step(0.1);
                o->value(10);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMinInitialSpeed);
              }
              { Fl_Value_Input* o = RadialShooter_MaxInitialSpeed = new Fl_Value_Input(1188, 384, 85, 25, "Max (m/s)");
                o->tooltip("The maximum starting velocity of each particle");
                o->maximum(1000);
                o->step(0.1);
                o->value(10);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMaxInitialSpeed);
              }
              o->end();
            }
            { Fl_Group* o = new Fl_Group(919, 444, 434, 114, "Initial Rotational Velocity Range");
              o->tooltip("The inital rotational velocity range the Shooter applies to each particle");
              o->box(FL_ENGRAVED_BOX);
              { Fl_Group* o = new Fl_Group(1003, 453, 125, 94, "Min(rad/sec)");
                o->box(FL_ENGRAVED_FRAME);
                o->align(FL_ALIGN_LEFT);
                { Fl_Value_Input* o = RadialShooter_MinInitialRotationalSpeedX = new Fl_Value_Input(1051, 458, 70, 25, "X Axis");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMinInitialRotationalSpeedX);
                }
                { Fl_Value_Input* o = RadialShooter_MinInitialRotationalSpeedY = new Fl_Value_Input(1051, 488, 70, 25, "Y Axis");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMinInitialRotationalSpeedY);
                }
                { Fl_Value_Input* o = RadialShooter_MinInitialRotationalSpeedZ = new Fl_Value_Input(1051, 518, 70, 24, "Z Axis");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMinInitialRotationalSpeedZ);
                }
                o->end();
              }
              { Fl_Group* o = new Fl_Group(1218, 453, 125, 95, "Max(rad/sec)");
                o->box(FL_ENGRAVED_FRAME);
                o->align(FL_ALIGN_LEFT);
                { Fl_Value_Input* o = RadialShooter_MaxInitialRotationalSpeedX = new Fl_Value_Input(1265, 458, 70, 25, "X Axis");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMaxInitialRotationalSpeedX);
                }
                { Fl_Value_Input* o = RadialShooter_MaxInitialRotationalSpeedY = new Fl_Value_Input(1265, 488, 70, 25, "Y Axis");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMaxInitialRotationalSpeedY);
                }
                { Fl_Value_Input* o = RadialShooter_MaxInitialRotationalSpeedZ = new Fl_Value_Input(1265, 518, 70, 25, "Z Axis");
                o->minimum(-10);
                o->maximum(10);
                o->step(0.1);
                o->callback((Fl_Callback*)psEditorGUI_RadialShooter_SetMaxInitialRotationalSpeedZ);
                }
                o->end();
              }
              o->end();
            }
            o->end();
          }
          { Fl_Choice* o = new Fl_Choice(1129, 135, 150, 25, "Shooter Type");
            o->down_box(FL_BORDER_BOX);
            o->callback((Fl_Callback*)psEditorGUI_Shooter_SetType);
            o->menu(menu_Shooter);
          }
          o->end();
        }
        { Fl_Group* o = new Fl_Group(904, 65, 490, 510, "Program");
          o->hide();
          { Fl_Browser* o = Program_Operators = new Fl_Browser(1034, 120, 150, 130, "Operators");
            o->type(2);
            o->callback((Fl_Callback*)psEditor_Program_OperatorsChanged);
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Button* o = new Fl_Button(1194, 120, 130, 25, "New Force");
            o->callback((Fl_Callback*)psEditorGUI_Program_NewForce);
          }
          { Fl_Button* o = new Fl_Button(1194, 155, 130, 25, "New Acceleration");
            o->callback((Fl_Callback*)psEditorGUI_Program_NewAcceleration);
          }
          { Fl_Button* o = new Fl_Button(1194, 190, 130, 25, "New Fluid Friction");
            o->callback((Fl_Callback*)psEditorGUI_Program_NewFluidFriction);
          }
          { Fl_Button* o = Program_DeleteOperator = new Fl_Button(1194, 225, 130, 25, "Delete Operator");
            o->callback((Fl_Callback*)psEditorGUI_Program_DeleteOperator);
          }
          { Fl_Group* o = FluidFrictionParameters = new Fl_Group(924, 305, 360, 160, "Fluid Friction Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Button* o = new Fl_Button(1164, 330, 90, 25, "Air");
              o->callback((Fl_Callback*)psEditorGUI_FluidFriction_Air);
            }
            { Fl_Button* o = new Fl_Button(1164, 360, 90, 25, "Water");
              o->callback((Fl_Callback*)psEditorGUI_FluidFriction_Water);
            }
            { Fl_Value_Input* o = FluidFriction_Density = new Fl_Value_Input(1069, 330, 80, 25, "Density");
              o->step(0.001);
              o->value(1.2929);
              o->callback((Fl_Callback*)psEditorGUI_FluidFriction_SetDensity);
            }
            { Fl_Value_Input* o = FluidFriction_Viscosity = new Fl_Value_Input(1069, 360, 80, 25, "Viscosity");
              o->step(0.0001);
              o->value(1.8e-005);
              o->callback((Fl_Callback*)psEditorGUI_FluidFriction_SetViscosity);
            }
            { Fl_Value_Input* o = FluidFriction_OverrideRadius = new Fl_Value_Input(1069, 390, 80, 25, "Override Radius");
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_FluidFriction_SetOverrideRadius);
            }
            o->end();
          }
          { Fl_Group* o = ForceParameters = new Fl_Group(989, 305, 305, 160, "Force Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Value_Input* o = Force_X = new Fl_Value_Input(1086, 335, 115, 25, "X");
              o->tooltip("A constant force on the X-axis");
              o->minimum(-1000);
              o->maximum(1000);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_Force_SetX);
            }
            { Fl_Value_Input* o = Force_Y = new Fl_Value_Input(1086, 365, 115, 25, "Y");
              o->tooltip("A constant force on the Y-axis");
              o->minimum(-1000);
              o->maximum(1000);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_Force_SetY);
            }
            { Fl_Value_Input* o = Force_Z = new Fl_Value_Input(1086, 395, 115, 25, "Z");
              o->tooltip("A constant force on the Z-axis");
              o->minimum(-1000);
              o->maximum(1000);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_Force_SetZ);
            }
            o->end();
          }
          { Fl_Group* o = AccelerationParameters = new Fl_Group(974, 305, 312, 160, "Acceleration Parameters");
            o->box(FL_DOWN_BOX);
            o->align(FL_ALIGN_BOTTOM|FL_ALIGN_INSIDE);
            o->hide();
            { Fl_Value_Input* o = Acceleration_X = new Fl_Value_Input(1072, 335, 115, 25, "X");
              o->minimum(-10);
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_Acceleration_SetX);
            }
            { Fl_Value_Input* o = Acceleration_Y = new Fl_Value_Input(1072, 365, 115, 25, "Y");
              o->minimum(-10);
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_Acceleration_SetY);
            }
            { Fl_Value_Input* o = Acceleration_Z = new Fl_Value_Input(1072, 395, 115, 25, "Z");
              o->minimum(-10);
              o->maximum(10);
              o->step(0.1);
              o->callback((Fl_Callback*)psEditorGUI_Acceleration_SetZ);
            }
            o->end();
          }
          o->end();
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(719, 325, 185, 265);
        o->box(FL_DOWN_BOX);
        { Fl_Button* o = new Fl_Button(729, 340, 65, 30, "@>");
          o->tooltip("Reset\'s the start time (\"plays\" the effect from start)");
          o->callback((Fl_Callback*)psEditorGUI_ResetLayers);
        }
        o->end();
      }
      o->end();
    }
    o->end();
    o->resizable(o);
  }
  return w;
}
