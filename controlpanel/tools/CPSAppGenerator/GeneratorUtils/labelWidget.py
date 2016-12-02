# # 
#    Copyright (c) 2016 Open Connectivity Foundation and AllJoyn Open
#    Source Project Contributors and others.
#    
#    All rights reserved. This program and the accompanying materials are
#    made available under the terms of the Apache License, Version 2.0
#    which accompanies this distribution, and is available at
#    http://www.apache.org/licenses/LICENSE-2.0

#
import xml.etree.ElementTree as xml
import commonWidget as common

class Label (common.Widget):

    def __init__(self, generated, labelElement, parentObjectPath, languageSetName) :
        common.Widget.__init__(self, generated, labelElement, parentObjectPath, languageSetName)
        self.widgetName = "LabelWidget"
        self.widgetType = "WIDGET_TYPE_LABEL"
        self.nonSecuredInterfaceName = "LabelPropertyInterfaces"
        self.hintPrefix = "LABEL_HINT_"

    def generateDefines(self, capName) :
        common.Widget.generateDefines(self, capName) 
        self.generated.defines += "#define {0}_LABEL_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, {1}, 1, 4)\n".format(capName, self.generated.definesIndx)

    def generateIdentify(self, capName, language) :
        common.Widget.generateIdentify(self, capName, language)
        self.generated.identify += """    case {0}_LABEL_PROPERTY:
        *widgetType = WIDGET_TYPE_LABEL;
        *propType = PROPERTY_TYPE_LABEL;
        *language = {2};
        return &{1};\n\n""".format(capName, self.name, language)

    def generateMandatoryVariables (self) :
        self.generated.initFunction  += "    initializeLabelWidget(&{0});\n".format(self.name)
        self.setNumLanguages()
        self.setEnabled()
        self.setLabel(1)
        self.generated.initFunction += "\n"

    def generateOptionalVariables (self) :
        self.setBgColor()
        self.setHints() 
    	
