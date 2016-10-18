# Copyright (c) Open Connectivity Foundation (OCF) and AllJoyn Open
#    Source Project (AJOSP) Contributors and others.
#
#    SPDX-License-Identifier: Apache-2.0
#
#    All rights reserved. This program and the accompanying materials are
#    made available under the terms of the Apache License, Version 2.0
#    which accompanies this distribution, and is available at
#    http://www.apache.org/licenses/LICENSE-2.0
#
#    Copyright (c) Open Connectivity Foundation and Contributors to AllSeen
#    Alliance. All rights reserved.
#
#    Permission to use, copy, modify, and/or distribute this software for
#    any purpose with or without fee is hereby granted, provided that the
#    above copyright notice and this permission notice appear in all
#    copies.
#
#     THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
#     WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
#     WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
#     AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
#     DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
#     PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
#     TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
#     PERFORMANCE OF THIS SOFTWARE.
#
import sys
import propertyWidget as pw
import actionWidget as aw
import labelWidget as lw
import commonWidget as common

class Container (common.Widget):

    def __init__(self, generated, containerElement, parentObjectPath, languageSetName, isRoot = 0) :
        common.Widget.__init__(self, generated, containerElement, parentObjectPath, languageSetName)
        self.isRoot = isRoot
        self.widgetName = "ContainerWidget"
        self.widgetType = "WIDGET_TYPE_CONTAINER"
        self.securedInterfaceName = "SecuredContainerInterfaces"
        self.nonSecuredInterfaceName = "ContainerInterfaces"
        self.hintPrefix = "LAYOUT_HINT_"
        if isRoot:
            self.objectPathSuffix = ""  

    def generate(self) :
        common.Widget.generate(self)
        self.generateChildElements()

    def generateChildElements (self) :
        elements = self.element.elements.sub_nodes

        for element in elements:
            elementType = element._name
            self.generated.initFunction += "\n"

            if elementType == "action" :
                action = aw.Action(self.generated, element, (self.parentObjectPath + self.objectPathSuffix), self.languageSetName)
                action.generate()
            elif elementType == "container" :
                container = Container(self.generated, element, (self.parentObjectPath + self.objectPathSuffix), self.languageSetName)
                container.generate()
            elif elementType == "scalarProperty" or elementType == "stringProperty" or elementType == "booleanProperty" :
                propertyW = pw.Property(self.generated, element, (self.parentObjectPath + self.objectPathSuffix), self.languageSetName)
                propertyW.generate()
            elif elementType == "dateProperty" or elementType == "timeProperty" :
                propertyW = pw.Property(self.generated, element, (self.parentObjectPath + self.objectPathSuffix), self.languageSetName)
                propertyW.generate()
            elif elementType == "labelProperty" :
                label = lw.Label(self.generated, element, (self.parentObjectPath + self.objectPathSuffix), self.languageSetName)
                label.generate()
            else :
                print >> sys.stderr, "ERROR - This type is not supported. Exiting " + elementType
                sys.exit(3)


